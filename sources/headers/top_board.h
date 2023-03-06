//
// Created by chest on 2023-02-28.
//

#ifndef MINESWEEPER_TOP_BOARD_H
#define MINESWEEPER_TOP_BOARD_H

#include "const.h"
#include <QPainter>
#include <QWidget>
#include <QRandomGenerator>


QT_BEGIN_NAMESPACE
namespace Ui { class TopBoard; }
QT_END_NAMESPACE

class TopBoard : public QWidget {
Q_OBJECT

public:
    explicit TopBoard(QWidget* parent = nullptr);

    ~TopBoard() override;

public:
    void loadImage();

    void mousePressEvent(QMouseEvent*) override;

    void paintEvent(QPaintEvent*) override;

    void drawBackground(QPainter& painter);

    void drawEmoji(QPainter& painter);

public:
    void setWinEmoji();

    void setFailEmoji();

private:
    Ui::TopBoard* ui;

    int emojiIndex = 0;

    int newEmojiIndex = 0;

    bool gameWin = false;
    bool gameFail = false;

    QList<QPixmap> emojiPixList;

    QPixmap winEmoji;
    QPixmap failEmoji;

    QRandomGenerator* randomGenerator;
};


#endif //MINESWEEPER_TOP_BOARD_H
