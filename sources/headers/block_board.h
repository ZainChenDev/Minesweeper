//
// Created by chest on 2023-02-27.
//

#ifndef MINESWEEPER_BLOCK_BOARD_H
#define MINESWEEPER_BLOCK_BOARD_H

#include "block.h"
#include <iostream>
#include <QGridLayout>
#include <QWidget>
#include <QPainter>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class BlockBoard; }
QT_END_NAMESPACE

class BlockBoard : public QWidget {
Q_OBJECT

public:
    //BlockBoard(QList<QPoint>&, QList<QList<Block*>>&);
    BlockBoard(QList<QList<Block*>>&, int);

    ~BlockBoard() override;

    void setMine();

    void setBlockConnect();

    void singleClickOpen();

    void openEmpty(Block*);

    void dfsFindEmpty(QPoint);

    void openMine();

    void judgeIsWin();

    void doubleClickOpen();

public:
    void gameWin();

    void gameFail();

    void paintEvent(QPaintEvent*) override;

signals:
    gameStartSignal();
    //gameStartSignal(QPoint);
    addMovesSignal();
    //openGoodBlockSignal();
    gameWinSignal();
    gameFailSignal();

private:
    Ui::BlockBoard* ui;

    QGridLayout* gridLayout = nullptr;

    int rows;
    int cols;

    int mineInitCount = 0;
    int goodBlockCount = 0;

    bool gameStarted = false;

    QList<QPoint> minePos;
    QList<QList<Block*>> blocks;

    void showDebug();

    bool inBoard(QPoint point);

    void openEdgeNumBlock(QPoint point);


    void initMine(QPoint point);

    void setNumber();

    int calcNumber(Block* block);

    void openBlock(Block* block);
};


#endif //MINESWEEPER_BLOCK_BOARD_H
