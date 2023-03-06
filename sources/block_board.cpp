//
// Created by chest on 2023-02-27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_block_board.h" resolved

#include <QRandomGenerator>
#include <QtConcurrent>
#include "headers/block_board.h"
#include "ui_block_board.h"


BlockBoard::BlockBoard(QList<QList<Block*>>& blocks, int mineInitCount) : ui(new Ui::BlockBoard) {
    ui->setupUi(this);

    this->blocks = blocks;

    this->rows = blocks.size();
    this->cols = blocks[0].size();

    this->mineInitCount = mineInitCount;
    goodBlockCount = rows * cols - mineInitCount;

    gridLayout = new QGridLayout();
    gridLayout->setSpacing(kBlockSpacing);
    this->setLayout(gridLayout);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            gridLayout->addWidget(blocks[i][j], i, j);
        }
    }

    //showDebug();
    setBlockConnect();
}

BlockBoard::~BlockBoard() {
    delete ui;
}

void BlockBoard::setMine() {

}

/**
 * 为每个Block设置点击连接，如果点击左键，则打开Block
 */
void BlockBoard::setBlockConnect() {
    for (const auto& list: blocks) {
        for (const auto& pBlock: list) {
            connect(pBlock, &Block::leftClickSignal, this, &BlockBoard::singleClickOpen);
            connect(pBlock, &Block::leftDoubleClickSignal, this, &BlockBoard::doubleClickOpen);
        }
    }
}

/**
 * 监听到左键点击一个Block，如果是第一次点击，则初始化雷，否则打开Block
 */
void BlockBoard::singleClickOpen() {
    // MOVES增加
    emit addMovesSignal();

    auto* pBlock = qobject_cast<Block*>(sender());

    if (!gameStarted) {
        // 打开第一个Block后，游戏开始，TIME开始计时
        initMine(pBlock->getPos());
        emit gameStartSignal();
        gameStarted = true;
    }

    openBlock(pBlock);
}

/**
 * 打开一个Block，包括直接点击Block和被双击打开的周围Block
 * 1.如果是雷
 *   打开所有的雷，并禁止点击。
 * 2.如果非雷
 *   (1).如果数字非0，则仅打开当前Block，并立即刷新当前Block。
 *   (2).如果数字是0，则不仅打开当前Block，还需要打开所有相连的0 Block以及与打开区域接壤的一圈非0 Block。
 *
 * @param block 要打开的Block
 */
void BlockBoard::openBlock(Block* block) {
    if (block->isMine()) {
        /////////////// Warning 打开一个雷，游戏失败，会导致资源被释放！ ///////////////
        openMine();
    } else {
        if (block->getNumber() > 0) {
            block->open();
            //block->update();
            /////////////// Warning 如果正好打开最后一个非雷Block，会导致资源被释放！ ///////////////
            judgeIsWin();
        } else {
            openEmpty(block);
            //update();
        }
    }

    // 如果资源被释放，此处执行的方法会对空悬指针进行操作，导致崩溃
    // emit addMovesSignal();
}

/**
 * 在点击打开第一个block后，生成雷并添加数字
 * @param point 第一个打开的雷的坐标
 */
void BlockBoard::initMine(QPoint point) {
    // 随机生成网格中的雷，并记录坐标
    QRandomGenerator* randomGenerator = QRandomGenerator::global();

    for (int i = 0; i < mineInitCount; i++) {
        int x, y;
        do {
            x = randomGenerator->bounded(0, rows - 1);
            y = randomGenerator->bounded(0, cols - 1);
        } while (minePos.contains(QPoint(x, y)) || QPoint(x, y) == point);
        minePos.append(QPoint(x, y));

        blocks[x][y]->setMine(true);
    }


    setNumber();
    showDebug();
}

void BlockBoard::setNumber() {
    // 只有雷的周围8个位置才会出现>0的数字，所以只需要设置雷的周围8个位置
    for (const auto& pos: minePos) {

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int x = pos.x() + i;
                int y = pos.y() + j;
                if (!inBoard(QPoint(x, y))) {
                    continue;
                }
                blocks[x][y]->setNumber(calcNumber(blocks[x][y]));
            }
        }

    }
}

/**
 * 计算指定Block周围八个位置有几个雷
 * @param block 指定Block的指针
 * @return 周围八个位置雷的数量
 */
int BlockBoard::calcNumber(Block* block) {
    int number = 0;
    /*
     * (-1,-1) (-1,0) (-1,+1)
     * (0,-1)    B    (0,+1)
     * (+1,-1) (+1,0) (+1,+1)
     */
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // 如果是自己，或者坐标超出rows*cols范围，跳过
            if (i == 0 && j == 0) {
                continue;
            }
            int x = block->getPos().x() + i;
            int y = block->getPos().y() + j;
            if (!inBoard(QPoint(x, y))) {
                continue;
            }
            // 如果发现一个雷，中心Block的数字加1
            if (blocks[x][y]->isMine()) {
                number++;
            }
        }
    }
    return number;
}

void BlockBoard::openEmpty(Block* pBlock) {
    // 在子线程中执行，防止卡顿
    QFuture<void> future = QtConcurrent::run(&BlockBoard::dfsFindEmpty, this, pBlock->getPos());
    //dfsFindEmpty(pBlock->getPos());
}

//深度优先搜索，打开所有相连的0 Block
void BlockBoard::dfsFindEmpty(QPoint point) {
    // 如果坐标超出rows*cols范围，跳过
    if (!inBoard(point)) {
        return;
    }
    // 如果 已经被标记/已经被打开了/数字不为0，则跳过
    int x = point.x(), y = point.y();
    if (blocks[x][y]->isMarked() || blocks[x][y]->isOpened() || blocks[x][y]->getNumber() != 0) {
        return;
    }

    blocks[x][y]->open();
    judgeIsWin();

    // 打开相连0区域接壤的非0 Block
    openEdgeNumBlock(point);

    dfsFindEmpty(QPoint(x + 1, y));
    dfsFindEmpty(QPoint(x, y + 1));
    dfsFindEmpty(QPoint(x - 1, y));
    dfsFindEmpty(QPoint(x, y - 1));
}

/**
 * 打开相连0区域接壤的非0 Block
 * @param point 指定0 Block的坐标
 */
void BlockBoard::openEdgeNumBlock(QPoint point) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int x = point.x() + i, y = point.y() + j;
            if (!inBoard(QPoint(x, y))) {
                continue;
            }
            if (blocks[x][y]->isOpened() || blocks[x][y]->isMarked() || blocks[x][y]->getNumber() <= 0) {
                continue;
            }
            // 寻找周围8个位置所有 未被打开 & 未被标记 的非0 Block
            blocks[x][y]->open();
            judgeIsWin();
        }
    }
}

/**
 * 禁止当前Widget及所有Block（子Widget）的鼠标点击，并打开所有的雷。
 */
void BlockBoard::openMine() {
    for (int i = 0; i < minePos.size(); i++) {
        blocks[minePos[i].x()][minePos[i].y()]->open();
    }
    gameFail();
}

/**
 * 每打开一个Block，判断是否胜利
 *
 * 凡是调用Block::poen()的地方都需要调用judgeIsWin()。
 * 凡是调用BlockBoard::openBlock()的地方都不需要调用。
 *
 * 如果被打开的Block被再次调用open()，虽然不会再次打开，但是会再次调用judgeIsWin()，导致goodBlockCount减小。
 *     所以务必确保已被打开的Block不会再次调用open()。（为减小开销，不在Block::open()中判断是否已经被打开）
 */
void BlockBoard::judgeIsWin() {
    goodBlockCount--;
    if (goodBlockCount == 0) {
        gameWin();
    }
}

/**
 * 双击一个被打开的>0数字Block，如果周围8个位置的标记数量等于自身数字，即玩家已经认定自己标记了正确的雷。
 * 所以直接打开周围8个位置未被标记的Block。
 * 被自动打开的Block可能会是雷。
 */
void BlockBoard::doubleClickOpen() {
    emit addMovesSignal();
    auto* pBlock = qobject_cast<Block*>(sender());

    int surroundMarkedCount = 0;

    // 计算周围8个位置被标记的Block数量
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // 如果是自己，或者坐标超出rows*cols范围，跳过
            if (i == 0 && j == 0) {
                continue;
            }
            int x = pBlock->getPos().x() + i;
            int y = pBlock->getPos().y() + j;
            if (!inBoard(QPoint(x, y))) {
                continue;
            }
            if (blocks[x][y]->isMarked()) {
                surroundMarkedCount++;
            }
        }
    }

    // 如果周围8个位置的标记数量等于该Block的数字，打开剩下未被标记的Block
    if (surroundMarkedCount == pBlock->getNumber()) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                // 如果是自己，或者坐标超出rows*cols范围，跳过
                if (i == 0 && j == 0) {
                    continue;
                }
                int x = pBlock->getPos().x() + i;
                int y = pBlock->getPos().y() + j;
                if (!inBoard(QPoint(x, y))) {
                    continue;
                }
                if (!blocks[x][y]->isMarked() && !blocks[x][y]->isOpened()) {
                    openBlock(blocks[x][y]);
                }
            }
        }
    }
}

bool BlockBoard::inBoard(QPoint point) {
    if (point.x() < 0 || point.x() >= rows || point.y() < 0 || point.y() >= cols) {
        return false;
    } else {
        return true;
    }
}

void BlockBoard::gameWin() {
    setAttribute(Qt::WA_TransparentForMouseEvents, true);
    emit gameWinSignal();
}

void BlockBoard::gameFail() {
    setAttribute(Qt::WA_TransparentForMouseEvents, true);
    emit gameFailSignal();
}

void BlockBoard::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    QPen pen(Color::BlockBoardBgColor);
    painter.setPen(pen);

    QBrush brush(Color::BlockBoardBgColor);
    painter.setBrush(brush);

    QRect rect(0, 0, this->width(), this->height());
    painter.drawRoundedRect(rect, 10, 10);
}

void BlockBoard::showDebug() {
    std::cout << "//////////// BlockBoard Show Debug Begin  ////////////" << std::endl;
    // 打印blocks
    for (const auto& list: blocks) {
        for (const auto& item: list) {
            if (item->isMine()) {
                std::cout << "X ";
            } else if (item->getNumber() != 0) {
                std::cout << item->getNumber() << " ";
            } else {
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "//////////// BlockBoard Show Debug End ////////////" << std::endl;
}


