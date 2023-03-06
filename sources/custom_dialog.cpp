//
// Created by chest on 2023-03-02.
//

// You may need to build the project (run Qt uic code generator) to get "ui_custom_dialog.h" resolved

#include <QIntValidator>
#include "headers/custom_dialog.h"
#include "ui_custom_dialog.h"


CustomDialog::CustomDialog(QWidget* parent) :
        QDialog(parent), ui(new Ui::CustomDialog) {
    ui->setupUi(this);

    setWindowTitle("Custom");

    setWindowIcon(QIcon(":/resources/images/custom.png"));

    ui->rowsLabel->setText(QString("行数(%1-%2):").arg(kMinCustomRows).arg(kMaxCustomRows));
    ui->colsLabel->setText(QString("列数(%1-%2):").arg(kMinCustomCols).arg(kMaxCustomCols));
    ui->mineLabel->setText(QString("雷数(%1-%2):").arg(kMinCustomMineCount).arg(kMaxCustomMineCount));


    ui->rowsEdit->setText(QString::number(rows));
    ui->colsEdit->setText(QString::number(cols));
    ui->mineEdit->setText(QString::number(mineCount));

    //ui->rowsEdit->setPlaceholderText("请输入9-24");

    // 使用QIntValidator限制器，只能限制类型和位数。。。不能限制范围值
//    ui->rowsEdit->setValidator(new QIntValidator(9, 24, this));
//    ui->colsEdit->setValidator(new QIntValidator(9, 30, this));
//    ui->mineEdit->setValidator(new QIntValidator(10, 668, this));

    // 限制只能输入数字
    QRegularExpression regExp("^[0-9]*$");
    auto* validator = new QRegularExpressionValidator(regExp, this);
    ui->rowsEdit->setValidator(validator);
    ui->colsEdit->setValidator(validator);
    ui->mineEdit->setValidator(validator);

    setRowsEditConnect();
    setColsEditConnect();
    setMineEditConnect();

    connect(ui->commitBtn, &QPushButton::clicked, [this] {
        emit commitCustomData();
    });

    connect(ui->cancelBtn, &QPushButton::clicked, [this] {
        close();
    });
}

CustomDialog::~CustomDialog() {
    delete ui;
}

void CustomDialog::setRowsEditConnect() {
    connect(ui->rowsEdit, &QLineEdit::editingFinished, [this] {
        rows = ui->rowsEdit->text().toInt();
        if (rows < kMinCustomRows) {
            QMessageBox box(QMessageBox::Warning, "Warning", "输入的值太小！", QMessageBox::Ok, this);
            box.exec();
            ui->rowsEdit->setText(QString::number(kMinCustomRows));
        }
        if (rows > kMaxCustomRows) {
            QMessageBox box(QMessageBox::Warning, "Warning", "输入的值太大！", QMessageBox::Ok, this);
            box.exec();
            ui->rowsEdit->setText(QString::number(kMaxCustomRows));
        }
    });
}

void CustomDialog::setColsEditConnect() {
    connect(ui->colsEdit, &QLineEdit::editingFinished, [this] {
        cols = ui->colsEdit->text().toInt();
        if (cols < kMinCustomCols) {
            QMessageBox box(QMessageBox::Warning, "Warning", "输入的值太小！", QMessageBox::Ok, this);
            box.exec();
            ui->colsEdit->setText(QString::number(kMinCustomCols));
        }
        if (cols > kMaxCustomCols) {
            QMessageBox box(QMessageBox::Warning, "Warning", "输入的值太大！", QMessageBox::Ok, this);
            box.exec();
            ui->colsEdit->setText(QString::number(kMaxCustomCols));
        }
    });
}

void CustomDialog::setMineEditConnect() {
    connect(ui->mineEdit, &QLineEdit::editingFinished, [this] {
        mineCount = ui->mineEdit->text().toInt();
        if (mineCount < kMinCustomMineCount) {
            QMessageBox box(QMessageBox::Warning, "Warning", "输入的值太小！", QMessageBox::Ok, this);
            box.exec();
            ui->mineEdit->setText(QString::number(kMinCustomMineCount));
        }

        // 根据当前已设置的行数和列数，最大的合理雷数量
        int currMaxMineCount = kMaxMineProportion * rows * cols;

        // 超过当前设置的合理值，但是没超过总体允许的最大值，则设置为当前合理值
        if (mineCount > currMaxMineCount && mineCount < kMaxCustomMineCount) {
            QMessageBox box(QMessageBox::Warning, "Warning",
                            QString("根据已设置的行数和列数，地雷的数量必须在%1和%2之间")
                                    .arg(kMinCustomMineCount).arg(currMaxMineCount),
                            QMessageBox::Ok, this);
            box.exec();
            ui->mineEdit->setText(QString::number(currMaxMineCount));

        } else if (mineCount > kMaxCustomMineCount) {
            // 超过总体允许最大值，设置为总体最大值
            QMessageBox box(QMessageBox::Warning, "Warning", "输入的值太大！", QMessageBox::Ok, this);
            box.exec();
            ui->mineEdit->setText(QString::number(currMaxMineCount));
        }
    });
}
