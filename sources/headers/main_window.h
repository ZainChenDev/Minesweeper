//
// Created by chest on 2023-02-24.
//

#ifndef MINESWEEPER_MAIN_WINDOW_H
#define MINESWEEPER_MAIN_WINDOW_H

#include "block.h"
#include "block_board.h"
#include "const.h"
#include "top_board.h"
#include "bottom_board.h"
#include "game_over_dialog.h"
#include "custom_dialog.h"
#include "about_dialog.h"
#include <iostream>
#include <QMainWindow>
#include <QRandomGenerator>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

public:
    void setEasyLevel();

    void setNormalLevel();

    void setHardLevel();

    void setCustomLevel();

public:
    void calcSize();

    void setGameOverDialog();

public:
    void release();

    void addLayout();

    void start();

public:
    void initEmptyBlocks();

public:
    void setCustomDialog();

    void setAboutDialog();

public:
    void addTopBoard();

    void setTopBoardConnect();

    void addBlockBoard();

    void addBottomBoard();

    void setBottomBoardConnect();

    void setDialogConnect();

public:
    void paintEvent(QPaintEvent*) override;

private:
    Ui::MainWindow* ui;

private:
    int topBoardHeight;
    int bottomBoardHeight;

private:
    int rows = 0;
    int cols = 0;
    int mineInitCount = 0;

    QList<QList<Block*>> blocks;

private:
    QVBoxLayout* vBoxLayout = nullptr;

    TopBoard* topBoard = nullptr;
    BlockBoard* blockBoard = nullptr;
    BottomBoard* bottomBoard = nullptr;

    GameOverDialog* gameOverDialog = nullptr;
    CustomDialog* customDialog = nullptr;
    AboutDialog* aboutDialog = nullptr;
};


#endif //MINESWEEPER_MAIN_WINDOW_H
