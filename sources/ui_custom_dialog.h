/********************************************************************************
** Form generated from reading UI file 'custom_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOM_DIALOG_H
#define UI_CUSTOM_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *rowsEdit;
    QLabel *mineLabel;
    QLabel *colsLabel;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QLineEdit *mineEdit;
    QLabel *rowsLabel;
    QLineEdit *colsEdit;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *commitBtn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *CustomDialog)
    {
        if (CustomDialog->objectName().isEmpty())
            CustomDialog->setObjectName(QString::fromUtf8("CustomDialog"));
        CustomDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(CustomDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(CustomDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        rowsEdit = new QLineEdit(widget);
        rowsEdit->setObjectName(QString::fromUtf8("rowsEdit"));

        gridLayout->addWidget(rowsEdit, 0, 3, 1, 1);

        mineLabel = new QLabel(widget);
        mineLabel->setObjectName(QString::fromUtf8("mineLabel"));
        QFont font;
        font.setFamilies({QString::fromUtf8("\350\213\271\346\226\271 \345\270\270\350\247\204")});
        font.setPointSize(11);
        mineLabel->setFont(font);

        gridLayout->addWidget(mineLabel, 4, 1, 1, 1);

        colsLabel = new QLabel(widget);
        colsLabel->setObjectName(QString::fromUtf8("colsLabel"));
        colsLabel->setFont(font);

        gridLayout->addWidget(colsLabel, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        mineEdit = new QLineEdit(widget);
        mineEdit->setObjectName(QString::fromUtf8("mineEdit"));

        gridLayout->addWidget(mineEdit, 4, 3, 1, 1);

        rowsLabel = new QLabel(widget);
        rowsLabel->setObjectName(QString::fromUtf8("rowsLabel"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\350\213\271\346\226\271 \345\270\270\350\247\204")});
        font1.setPointSize(11);
        font1.setStyleStrategy(QFont::PreferAntialias);
        rowsLabel->setFont(font1);

        gridLayout->addWidget(rowsLabel, 0, 1, 1, 1);

        colsEdit = new QLineEdit(widget);
        colsEdit->setObjectName(QString::fromUtf8("colsEdit"));

        gridLayout->addWidget(colsEdit, 2, 3, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(CustomDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        commitBtn = new QPushButton(widget_2);
        commitBtn->setObjectName(QString::fromUtf8("commitBtn"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\350\213\271\346\226\271 \345\270\270\350\247\204")});
        commitBtn->setFont(font2);

        horizontalLayout->addWidget(commitBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        cancelBtn = new QPushButton(widget_2);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setFont(font2);

        horizontalLayout->addWidget(cancelBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addWidget(widget_2);


        retranslateUi(CustomDialog);

        QMetaObject::connectSlotsByName(CustomDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomDialog)
    {
        CustomDialog->setWindowTitle(QCoreApplication::translate("CustomDialog", "CustomDialog", nullptr));
        mineLabel->setText(QString());
        colsLabel->setText(QString());
        rowsLabel->setText(QString());
        commitBtn->setText(QCoreApplication::translate("CustomDialog", "\347\241\256\345\256\232", nullptr));
        cancelBtn->setText(QCoreApplication::translate("CustomDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomDialog: public Ui_CustomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOM_DIALOG_H
