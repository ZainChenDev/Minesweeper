//
// Created by chest on 2023-02-28.
//

#ifndef MINESWEEPER_GAME_OVER_DIALOG_H
#define MINESWEEPER_GAME_OVER_DIALOG_H

#include "const.h"
#include <QDialog>
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class GameOverDialog; }
QT_END_NAMESPACE

class GameOverDialog : public QDialog {
Q_OBJECT

public:
    explicit GameOverDialog(QWidget* parent = nullptr);

    ~GameOverDialog() override;

    bool isWin() const {
        return win;
    }

    void setWin(bool);

    void paintEvent(QPaintEvent*) override;

signals:
    void restartSignal();
    void quitSignal();

private:
    Ui::GameOverDialog* ui;

    bool win = false;

    QPixmap winEmoji;
    QPixmap failEmoji;

    void loadImage();
};


#endif //MINESWEEPER_GAME_OVER_DIALOG_H
