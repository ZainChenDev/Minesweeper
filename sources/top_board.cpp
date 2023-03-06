//
// Created by chest on 2023-02-28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_top_board.h" resolved

#include <QRandomGenerator>
#include "headers/top_board.h"
#include "ui_top_board.h"


TopBoard::TopBoard(QWidget* parent) :
        QWidget(parent), ui(new Ui::TopBoard) {
    ui->setupUi(this);

    loadImage();
    randomGenerator = QRandomGenerator::global();
}

TopBoard::~TopBoard() {
    delete ui;
}

void TopBoard::loadImage() {
    for (int i = 0; i < kMaxEmojiNumber; ++i) {
        QPixmap pix(QString(":/resources/images/emoji_%1.png").arg(QString::number(i)));
        emojiPixList.append(pix);
    }
    winEmoji.load(":/resources/images/emoji_win.png");
    failEmoji.load(":/resources/images/emoji_fail.png");
}

void TopBoard::mousePressEvent(QMouseEvent*) {
    do {
        newEmojiIndex = randomGenerator->bounded(0, kMaxEmojiNumber - 1);
    } while (newEmojiIndex == emojiIndex);

    update();
}

void TopBoard::setWinEmoji() {
    gameWin = true;
    update();
}

void TopBoard::setFailEmoji() {
    gameFail = true;
    update();
}

void TopBoard::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    drawBackground(painter);
    drawEmoji(painter);
}

void TopBoard::drawBackground(QPainter& painter) {
    QPen pen(Color::TopBoardBgColor);
    painter.setPen(pen);

    QBrush brush(Color::TopBoardBgColor);
    painter.setBrush(brush);

    QRect rect(0, 0, this->width(), this->height());
    painter.drawRoundedRect(rect, 10, 10);
}

/**
 * 在TopBoard中心区域绘制emoji
 * @param painter
 */
void TopBoard::drawEmoji(QPainter& painter) {
    int emojiLength = 0.7 * kTopBoardHeight;
    QRect rect(0.5 * (this->width() - emojiLength), 0.5 * (this->height() - emojiLength), emojiLength, emojiLength);

    if (!gameWin && !gameFail) {
        painter.drawPixmap(rect, emojiPixList[newEmojiIndex]);
        emojiIndex = newEmojiIndex;
    } else if (gameWin) {
        painter.drawPixmap(rect, winEmoji);
    } else {
        painter.drawPixmap(rect, failEmoji);
    }
}






