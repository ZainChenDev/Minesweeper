//
// Created by chest on 2023-02-27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Block.h" resolved

#include "headers/block.h"
#include "ui_Block.h"


Block::Block(QPoint point) : ui(new Ui::Block) {
    ui->setupUi(this);

    pos = point;
    length = kBlockLength;
    setFixedSize(length, length);

    id = "Block[" + QString::number(pos.x()) + "," + QString::number(pos.y()) + "]";

    loadImage();
}

Block::~Block() {
    delete ui;
}

void Block::loadImage() {
    blockImg.load(":/resources/images/block.png");
    flagImg.load(":/resources/images/flag.png");
    mineImg.load(":/resources/images/mine.png");
}


void Block::setMine(bool mine) {
    Block::mine = mine;
}

void Block::setNumber(int number) {
    Block::number = number;
}

/**
 * 打开当前Block，并刷新绘制。
 */
void Block::open() {
    if (opened) {
        return;
    }
    opened = true;

    update();
}

/**
 * 绘制Block
 * 1.未打开
 *  (1)未标记：显示block
 *  (2)已标记:显示block、flag
 * 2.已打开
 *  (1)是大于0的数字：显示数字
 *  (2)是雷：显示雷
 * @param event
 */
void Block::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHints(QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);

    QRect rect(0, 0, length, length);

    if (!opened) {
        painter.drawPixmap(rect, blockImg);
        if (marked) {
            painter.drawPixmap(rect, flagImg);
        }
    } else {
        if (!mine) {
            if (number > 0) {
                painter.setFont(QFont("Volkswagen-DemiBold", 20));
                painter.setPen(QPen(Color::NumberBlockColor));
                // 为了让数字居中，需要在前面加一个空格
                painter.drawText(rect, " " + QString::number(number));
            }
        } else {
            painter.drawPixmap(rect, mineImg);
        }
    }
}

/**
 * 鼠标点击，只有在未打开（is_open == false）时，点击才有效
 */
void Block::mousePressEvent(QMouseEvent* event) {
    if (!opened) {
        // 未标记 & 未打开 的情况下，左键才有效
        if (event->button() == Qt::LeftButton) {
            if (!marked) {
                // 点击一个Block，可能打开一个或若干个，所以委托给BlockBoard进行操作
                emit this->leftClickSignal();
            }
        } else if (event->button() == Qt::RightButton) {
            if (marked) {
                emit removeFlagSignal();
            } else {
                emit addFlagSignal();
            }
            marked = !marked;
            // 右键一个Block，涉及的Block只有自身，所以自行update
            update();
        }
    }

}

void Block::mouseDoubleClickEvent(QMouseEvent* event) {
    // 双击只有在已打开（is_open == true）且数字大于0时，才有效
    if (number > 0 && opened && !marked && event->button() == Qt::LeftButton) {
        emit leftDoubleClickSignal();
    }

}

