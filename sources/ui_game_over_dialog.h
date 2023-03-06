/********************************************************************************
** Form generated from reading UI file 'game_over_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_OVER_DIALOG_H
#define UI_GAME_OVER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOverDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *overInfoWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *restartBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *quitBtn;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *GameOverDialog)
    {
        if (GameOverDialog->objectName().isEmpty())
            GameOverDialog->setObjectName(QString::fromUtf8("GameOverDialog"));
        GameOverDialog->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameOverDialog->sizePolicy().hasHeightForWidth());
        GameOverDialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        GameOverDialog->setFont(font);
        verticalLayout = new QVBoxLayout(GameOverDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        overInfoWidget = new QWidget(GameOverDialog);
        overInfoWidget->setObjectName(QString::fromUtf8("overInfoWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(overInfoWidget->sizePolicy().hasHeightForWidth());
        overInfoWidget->setSizePolicy(sizePolicy1);
        overInfoWidget->setMinimumSize(QSize(0, 80));
        overInfoWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(overInfoWidget);

        widget = new QWidget(GameOverDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(0, 80));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        restartBtn = new QPushButton(widget);
        restartBtn->setObjectName(QString::fromUtf8("restartBtn"));

        horizontalLayout->addWidget(restartBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        quitBtn = new QPushButton(widget);
        quitBtn->setObjectName(QString::fromUtf8("quitBtn"));

        horizontalLayout->addWidget(quitBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget);


        retranslateUi(GameOverDialog);

        QMetaObject::connectSlotsByName(GameOverDialog);
    } // setupUi

    void retranslateUi(QDialog *GameOverDialog)
    {
        GameOverDialog->setWindowTitle(QCoreApplication::translate("GameOverDialog", "GameOverDialog", nullptr));
        restartBtn->setText(QCoreApplication::translate("GameOverDialog", "\345\206\215\347\216\251\344\270\200\346\254\241", nullptr));
        quitBtn->setText(QCoreApplication::translate("GameOverDialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameOverDialog: public Ui_GameOverDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_OVER_DIALOG_H
