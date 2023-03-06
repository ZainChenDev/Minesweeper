//
// Created by chest on 2023-02-28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_game_over_dialog.h" resolved

#include "headers/game_over_dialog.h"
#include "ui_game_over_dialog.h"


GameOverDialog::GameOverDialog(QWidget* parent) :
        QDialog(parent), ui(new Ui::GameOverDialog) {
    ui->setupUi(this);

    setFixedSize(400, 300);
    setWindowTitle("Game Over");

    this->win = win;

    loadImage();

    connect(ui->restartBtn, &QPushButton::clicked, [this] {
        emit restartSignal();
        close();
    });

    connect(ui->quitBtn, &QPushButton::clicked, [this] {
        emit quitSignal();
        //close();
    });
}

GameOverDialog::~GameOverDialog() {
    delete ui;
}

void GameOverDialog::loadImage() {
    winEmoji.load(":/resources/images/emoji_win.png");
    failEmoji.load(":/resources/images/emoji_fail_icon_hd.png");
}

void GameOverDialog::setWin(bool win) {
    this->win = win;
    update();

    ///////////// QLabel显示图片效果不好，所以绘制图片任务交给QPainter /////////////
//    QSize scaled_size = QSize(50, 50);
//
//    if (win) {
//        ui->emojiLabel->setPixmap(QPixmap(winEmoji).scaled(scaled_size, Qt::KeepAspectRatio, Qt::SmoothTransformation));
//        ui->textLabel->setText("Congratulation!");
//    } else {
//        ui->emojiLabel->setPixmap(failEmoji);
//        //ui->emojiLabel->setPixmap(QPixmap(failEmoji).scaled(scaled_size, Qt::KeepAspectRatio, Qt::SmoothTransformation));
//        ui->textLabel->setText("Good Luck\nNext Time!");
//    }
}

void GameOverDialog::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);

    QPen pen(Color::LightBlackTextColor);
    painter.setPen(pen);

    QFont font("Ubuntu", 20);
    painter.setFont(font);

    // 根据设置好字体、字号的文本内容计算合适的尺寸
    QFontMetrics fm(font);

    if (win) {
        int emojiStartX = 0.18 * ui->overInfoWidget->width();
        int emojiStartY = 0.5 * (ui->overInfoWidget->height() - kOverEmojiLength);
        QRect emojiRect(emojiStartX, emojiStartY, kOverEmojiLength, kOverEmojiLength);
        painter.drawPixmap(emojiRect, winEmoji);

        QSize winTextSize = fm.size(Qt::TextSingleLine, "Congratulation!");
        int textStartX = emojiStartX + kOverEmojiLength + 20;
        int textStartY = 0.5 * (ui->overInfoWidget->height() - winTextSize.height());
        QRect textRect(textStartX, textStartY, winTextSize.width(), winTextSize.height());
        painter.drawText(textRect, "Congratulations!");
    } else {
        int emojiStartX = 0.2 * ui->overInfoWidget->width();
        int emojiStartY = 0.5 * (ui->overInfoWidget->height() - kOverEmojiLength);
        QRect emojiRect(emojiStartX, emojiStartY, kOverEmojiLength, kOverEmojiLength);
        painter.drawPixmap(emojiRect, failEmoji);

        QSize failTextSize = fm.size(Qt::TextDontClip, "Good Luck\nNext Time!");
        int textStartX = emojiStartX + kOverEmojiLength + 30;
        int textStartY = 0.5 * (ui->overInfoWidget->height() - failTextSize.height());
        QRect textRect(textStartX, textStartY, failTextSize.width(), failTextSize.height());
        painter.drawText(textRect, "Good Luck\nNext Time!");
    }
}
