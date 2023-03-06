/********************************************************************************
** Form generated from reading UI file 'bottom_board.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTTOM_BOARD_H
#define UI_BOTTOM_BOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BottomBoard
{
public:
    QGridLayout *gridLayout;
    QLabel *movesLabel;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *movesTextLabel;
    QLabel *bombsTextLabel;
    QLabel *bombsLabel;
    QLabel *timeTextLabel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *timeLabel;

    void setupUi(QWidget *BottomBoard)
    {
        if (BottomBoard->objectName().isEmpty())
            BottomBoard->setObjectName(QString::fromUtf8("BottomBoard"));
        BottomBoard->resize(596, 398);
        QFont font;
        font.setPointSize(22);
        BottomBoard->setFont(font);
        gridLayout = new QGridLayout(BottomBoard);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        movesLabel = new QLabel(BottomBoard);
        movesLabel->setObjectName(QString::fromUtf8("movesLabel"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Ubuntu")});
        font1.setPointSize(22);
        font1.setStyleStrategy(QFont::PreferAntialias);
        movesLabel->setFont(font1);
        movesLabel->setStyleSheet(QString::fromUtf8("color: rgb(54, 54, 54);"));
        movesLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(movesLabel, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 6, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        movesTextLabel = new QLabel(BottomBoard);
        movesTextLabel->setObjectName(QString::fromUtf8("movesTextLabel"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri Light")});
        font2.setPointSize(20);
        font2.setStyleStrategy(QFont::PreferAntialias);
        movesTextLabel->setFont(font2);
        movesTextLabel->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 170);"));
        movesTextLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(movesTextLabel, 1, 3, 1, 1);

        bombsTextLabel = new QLabel(BottomBoard);
        bombsTextLabel->setObjectName(QString::fromUtf8("bombsTextLabel"));
        bombsTextLabel->setFont(font2);
        bombsTextLabel->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 170);"));
        bombsTextLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(bombsTextLabel, 1, 1, 1, 1);

        bombsLabel = new QLabel(BottomBoard);
        bombsLabel->setObjectName(QString::fromUtf8("bombsLabel"));
        bombsLabel->setFont(font1);
        bombsLabel->setStyleSheet(QString::fromUtf8("color: rgb(54, 54, 54);"));
        bombsLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(bombsLabel, 0, 1, 1, 1);

        timeTextLabel = new QLabel(BottomBoard);
        timeTextLabel->setObjectName(QString::fromUtf8("timeTextLabel"));
        timeTextLabel->setFont(font2);
        timeTextLabel->setStyleSheet(QString::fromUtf8("color: rgb(170, 170, 170);"));
        timeTextLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(timeTextLabel, 1, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        timeLabel = new QLabel(BottomBoard);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Ubuntu")});
        font3.setPointSize(24);
        font3.setStyleStrategy(QFont::PreferAntialias);
        timeLabel->setFont(font3);
        timeLabel->setStyleSheet(QString::fromUtf8("color: rgb(54, 54, 54);"));
        timeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(timeLabel, 0, 5, 1, 1);


        retranslateUi(BottomBoard);

        QMetaObject::connectSlotsByName(BottomBoard);
    } // setupUi

    void retranslateUi(QWidget *BottomBoard)
    {
        BottomBoard->setWindowTitle(QCoreApplication::translate("BottomBoard", "BottomBoard", nullptr));
        movesLabel->setText(QCoreApplication::translate("BottomBoard", "0", nullptr));
        movesTextLabel->setText(QCoreApplication::translate("BottomBoard", "MOVES", nullptr));
        bombsTextLabel->setText(QCoreApplication::translate("BottomBoard", "BOMBS", nullptr));
        bombsLabel->setText(QString());
        timeTextLabel->setText(QCoreApplication::translate("BottomBoard", "TIME", nullptr));
        timeLabel->setText(QCoreApplication::translate("BottomBoard", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BottomBoard: public Ui_BottomBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTTOM_BOARD_H
