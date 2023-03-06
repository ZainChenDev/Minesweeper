//
// Created by chest on 2023-02-27.
//

#ifndef MINESWEEPER_BLOCK_H
#define MINESWEEPER_BLOCK_H

#include "const.h"
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Block; }
QT_END_NAMESPACE

class Block : public QWidget {
Q_OBJECT


public:
    explicit Block(QPoint);

    ~Block() override;

    const QPoint& getPos() const {
        return pos;
    }

    void setPos(const QPoint& pos) {
        Block::pos = pos;
    }

    int getNumber() const {
        return number;
    }

    void setNumber(int);

    bool isMarked() const {
        return marked;
    }

    void setMarked(bool marked) {
        Block::marked = marked;
    }

    bool isOpened() const {
        return opened;
    }

    bool isMine() const {
        return mine;
    }

    void setMine(bool);

    void open();

    void loadImage();

    void paintEvent(QPaintEvent* event) override;

    void mousePressEvent(QMouseEvent* e) override;

    void mouseDoubleClickEvent(QMouseEvent*) override;

signals:

    void leftClickSignal();

    void leftDoubleClickSignal();

    void addFlagSignal();

    void removeFlagSignal();

private:
    Ui::Block* ui;

    QPoint pos;

    bool mine = false;

    int length = 0;

    int number = 0;

private:

    bool marked = false;

    bool opened = false;

    QString id;

private:
    QPixmap blockImg;
    QPixmap flagImg;
    QPixmap mineImg;
    QPixmap numberImg;

private:
    void setOpened(bool opened) {
        Block::opened = opened;
    }
};


#endif //MINESWEEPER_BLOCK_H
