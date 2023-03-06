//
// Created by chest on 2023-02-28.
//

#ifndef MINESWEEPER_BOTTOM_BOARD_H
#define MINESWEEPER_BOTTOM_BOARD_H

#include <QWidget>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class BottomBoard; }
QT_END_NAMESPACE

class BottomBoard : public QWidget {
Q_OBJECT

public:
    explicit BottomBoard(int);

    ~BottomBoard() override;

public:
    void addMoves();

    void subBombs();

    void addBombs();

    void timeStart();

    void timeStop();

private:
    Ui::BottomBoard* ui;

    int mine_init_count = 0;

    int bombs = 0;

    int moves = 0;

    int time = 0;

private:
    QTimer* timeTimer;
};


#endif //MINESWEEPER_BOTTOM_BOARD_H
