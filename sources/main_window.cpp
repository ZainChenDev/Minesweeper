//
// Created by chest on 2023-02-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved


#include "headers/main_window.h"
#include "ui_main_window.h"


MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setWindowTitle("Minesweeper");
    setWindowIcon(QIcon(":/resources/images/icon.png"));

    // 点击“新游戏”按钮，重开一个当前难度的游戏
    connect(ui->newGameAction, &QAction::triggered, this, &MainWindow::start);

    connect(ui->easyAction, &QAction::triggered, this, &MainWindow::setEasyLevel);
    connect(ui->normalAction, &QAction::triggered, this, &MainWindow::setNormalLevel);
    connect(ui->hardAction, &QAction::triggered, this, &MainWindow::setHardLevel);

    connect(ui->quitAction, &QAction::triggered, this, &MainWindow::close);

    setCustomDialog();

    setGameOverDialog();

    setAboutDialog();

    // 默认为简单难度
    setEasyLevel();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setEasyLevel() {
    rows = static_cast<int>(EasyLevel::ROWS);
    cols = static_cast<int>(EasyLevel::COLS);
    mineInitCount = static_cast<int>(EasyLevel::MINE_INIT_COUNT);

    start();
}

void MainWindow::setNormalLevel() {
    rows = static_cast<int>(NormalLevel::ROWS);
    cols = static_cast<int>(NormalLevel::COLS);
    mineInitCount = static_cast<int>(NormalLevel::MINE_INIT_COUNT);

    start();
}

void MainWindow::setHardLevel() {
    rows = static_cast<int>(HardLevel::ROWS);
    cols = static_cast<int>(HardLevel::COLS);
    mineInitCount = static_cast<int>(HardLevel::MINE_INIT_COUNT);

    start();
}

void MainWindow::setCustomLevel() {
    // 从自定义对话框中获取数据
    rows = customDialog->getRows();
    cols = customDialog->getCols();
    mineInitCount = customDialog->getMineCount();

    customDialog->close();

    start();
}

/**
 * 重新开始/重设难度 后，需要清空之前的数据。
 * 首先生成BlockBoard，BlockBoard的尺寸由其中的Block数量自行决定。
 * 然后生成VBoxLayout，添加各个Board，VBoxLayout的高度由其中的Widget共同决定，宽度等于BlockBoard。
 * 不指定其他Board的宽度，则会自动适应等于BlockBoard的宽度，所以只需手动指定TopBoard和BottomBoard的高度。
 */
void MainWindow::start() {
    if (vBoxLayout) {
        release();
    }

    initEmptyBlocks();

    calcSize();

    addLayout();

    addTopBoard();
    addBlockBoard();
    addBottomBoard();

    setTopBoardConnect();
    setBottomBoardConnect();

    setDialogConnect();

    setFixedSize(vBoxLayout->geometry().width(), vBoxLayout->geometry().height());
}

/**
 * 如果 重新开始/重设难度，则清空之前使用过的数据。
 */
void MainWindow::release() {
    //qDebug() << "=========== release sources! restart! ===========";

    blocks.clear();
    blocks.squeeze();

    delete topBoard;
    topBoard = nullptr;

    delete blockBoard;
    blockBoard = nullptr;

    delete bottomBoard;
    bottomBoard = nullptr;

    delete vBoxLayout;
    vBoxLayout = nullptr;
}

/**
 * 计算所有Board的尺寸
 */
void MainWindow::calcSize() {
    topBoardHeight = kTopBoardHeight;
    bottomBoardHeight = kBottomBoardHeight;
}

/**
 * 初始化空的Block，用于生成BlockBoard
 */
void MainWindow::initEmptyBlocks() {
    for (int i = 0; i < rows; ++i) {
        QList<Block*> row_blocks;
        for (int j = 0; j < cols; ++j) {
            auto* pBlock = new Block(QPoint(i, j));
            row_blocks.append(pBlock);
        }
        blocks.append(row_blocks);
    }
}

void MainWindow::setCustomDialog() {
    customDialog = new CustomDialog(this);
    connect(ui->customAction, &QAction::triggered, [this] {
        customDialog->exec();
    });
    connect(customDialog, &CustomDialog::commitCustomData, this, &MainWindow::setCustomLevel);
}

void MainWindow::addLayout() {
    vBoxLayout = new QVBoxLayout();
    ui->centralwidget->setLayout(vBoxLayout);
    // 设置四周的间距
    vBoxLayout->setContentsMargins(kMarginX, kTopMargin, kMarginX, kBottomMargin);
    // 设置每个Board之间的间距
    vBoxLayout->setSpacing(kBoardSpacing);
}

void MainWindow::addTopBoard() {
    topBoard = new TopBoard();
    topBoard->setFixedHeight(topBoardHeight);
    vBoxLayout->addWidget(topBoard);
}

void MainWindow::setTopBoardConnect() {
    connect(blockBoard, &BlockBoard::gameWinSignal, topBoard, &TopBoard::setWinEmoji);
    connect(blockBoard, &BlockBoard::gameFailSignal, topBoard, &TopBoard::setFailEmoji);
}

/**
 * 添加BlockBoard
 */
void MainWindow::addBlockBoard() {
    blockBoard = new BlockBoard(blocks, mineInitCount);
    // 打开第一个Block后，，游戏开始，立即生成雷坐标，生成完毕后再执行后序任务
    //connect(blockBoard, &BlockBoard::gameStartSignal, this, &MainWindow::initMine, Qt::DirectConnection);
    vBoxLayout->addWidget(blockBoard);
}

void MainWindow::addBottomBoard() {
    bottomBoard = new BottomBoard(mineInitCount);
    bottomBoard->setFixedHeight(bottomBoardHeight);
    vBoxLayout->addWidget(bottomBoard);
}

void MainWindow::setBottomBoardConnect() {
    for (const auto& list: blocks) {
        for (const auto& pBlock: list) {
            // Block添加一个flag后，BOMBS计数加1
            connect(pBlock, &Block::addFlagSignal, bottomBoard, &BottomBoard::subBombs);
            // Block移除一个flag后，BOMBS计数减1
            connect(pBlock, &Block::removeFlagSignal, bottomBoard, &BottomBoard::addBombs);
        }
    }

    // 每次手动打开一个Block，就把MOVES加1
    connect(blockBoard, &BlockBoard::addMovesSignal, bottomBoard, &BottomBoard::addMoves);

    // 打开第一个Block后，游戏开始，TIME开始计时
    connect(blockBoard, &BlockBoard::gameStartSignal, bottomBoard, &BottomBoard::timeStart);

    // 游戏胜利或失败后，TIME都停止计时
    connect(blockBoard, &BlockBoard::gameWinSignal, bottomBoard, &BottomBoard::timeStop);
    connect(blockBoard, &BlockBoard::gameFailSignal, bottomBoard, &BottomBoard::timeStop);
}

/**
 * 游戏结束（胜利或失败）后，弹出窗口
 */
void MainWindow::setDialogConnect() {
    connect(blockBoard, &BlockBoard::gameWinSignal, [this] {
        gameOverDialog->setWin(true);
        // 延时一秒后弹出GameOverDialog
        QTimer::singleShot(1000, gameOverDialog, SLOT(exec()));
    });
    connect(blockBoard, &BlockBoard::gameFailSignal, [this] {
        gameOverDialog->setWin(false);
        QTimer::singleShot(1000, gameOverDialog, SLOT(exec()));
    });
}

void MainWindow::setGameOverDialog() {
    gameOverDialog = new GameOverDialog(this);

    // 在GameOverDialogConnect中点击”再玩一局“后，重新开始原有难度的游戏
    connect(gameOverDialog, &GameOverDialog::restartSignal, this, &MainWindow::start);
    // GameOverDialogConnect退出按钮，关闭游戏
    connect(gameOverDialog, &GameOverDialog::quitSignal, [this] {
        gameOverDialog->close();
        close();
    });
}

void MainWindow::setAboutDialog() {
    aboutDialog = new AboutDialog(this);
    connect(ui->aboutAction, &QAction::triggered, [this] {
        aboutDialog->exec();
    });
}

void MainWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.fillRect(0, 0, this->width(), this->height(), QBrush(Color::BgColor));
}
