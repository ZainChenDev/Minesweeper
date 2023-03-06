/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newGameAction;
    QAction *easyAction;
    QAction *aboutAction;
    QAction *quitAction;
    QAction *normalAction;
    QAction *hardAction;
    QAction *customAction;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        newGameAction = new QAction(MainWindow);
        newGameAction->setObjectName(QString::fromUtf8("newGameAction"));
        easyAction = new QAction(MainWindow);
        easyAction->setObjectName(QString::fromUtf8("easyAction"));
        aboutAction = new QAction(MainWindow);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        quitAction = new QAction(MainWindow);
        quitAction->setObjectName(QString::fromUtf8("quitAction"));
        normalAction = new QAction(MainWindow);
        normalAction->setObjectName(QString::fromUtf8("normalAction"));
        hardAction = new QAction(MainWindow);
        hardAction->setObjectName(QString::fromUtf8("hardAction"));
        customAction = new QAction(MainWindow);
        customAction->setObjectName(QString::fromUtf8("customAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(newGameAction);
        menu->addSeparator();
        menu->addAction(easyAction);
        menu->addAction(normalAction);
        menu->addAction(hardAction);
        menu->addAction(customAction);
        menu->addSeparator();
        menu->addAction(aboutAction);
        menu->addSeparator();
        menu->addAction(quitAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        newGameAction->setText(QCoreApplication::translate("MainWindow", "\346\226\260\346\270\270\346\210\217", nullptr));
        easyAction->setText(QCoreApplication::translate("MainWindow", "\347\256\200\345\215\225", nullptr));
        aboutAction->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        quitAction->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        normalAction->setText(QCoreApplication::translate("MainWindow", "\346\231\256\351\200\232", nullptr));
        hardAction->setText(QCoreApplication::translate("MainWindow", "\345\233\260\351\232\276", nullptr));
        customAction->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
