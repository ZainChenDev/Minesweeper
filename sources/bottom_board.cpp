//
// Created by chest on 2023-02-28.
//

// You may need to build the project (run Qt uic code generator) to get "ui_bottom_board.h" resolved

#include "headers/bottom_board.h"
#include "ui_bottom_board.h"


BottomBoard::BottomBoard(int mine_init_count) : ui(new Ui::BottomBoard) {
    ui->setupUi(this);

    this->mine_init_count = mine_init_count;
    bombs = mine_init_count;

    ui->bombsLabel->setText(QString::number(bombs) + "/" + QString::number(mine_init_count));
}

BottomBoard::~BottomBoard() {
    delete ui;
}

void BottomBoard::addMoves() {
    moves++;
    ui->movesLabel->setText(QString::number(moves));
}

void BottomBoard::subBombs() {
    bombs--;
    ui->bombsLabel->setText(QString::number(bombs) + "/" + QString::number(mine_init_count));
}

void BottomBoard::addBombs() {
    bombs++;
    ui->bombsLabel->setText(QString::number(bombs) + "/" + QString::number(mine_init_count));
}

void BottomBoard::timeStart() {
    timeTimer = new QTimer(this);
    timeTimer->start(1000);
    connect(timeTimer, &QTimer::timeout, [this] {
        time++;
        ui->timeLabel->setText(QString::number(time));
    });
}

void BottomBoard::timeStop() {
    timeTimer->stop();
}


