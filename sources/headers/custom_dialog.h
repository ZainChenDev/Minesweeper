//
// Created by chest on 2023-03-02.
//

#ifndef MINESWEEPER_CUSTOM_DIALOG_H
#define MINESWEEPER_CUSTOM_DIALOG_H

#include "const.h"
#include <QDialog>
#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <QLineEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class CustomDialog; }
QT_END_NAMESPACE

class CustomDialog : public QDialog {
Q_OBJECT

public:
    explicit CustomDialog(QWidget* parent = nullptr);

    ~CustomDialog() override;

signals:

    commitCustomData();

public:
    int getRows() const {
        return rows;
    }

    void setRows(int rows) {
        CustomDialog::rows = rows;
    }

    int getCols() const {
        return cols;
    }

    void setCols(int cols) {
        CustomDialog::cols = cols;
    }

    int getMineCount() const {
        return mineCount;
    }

    void setMineCount(int mineCount) {
        CustomDialog::mineCount = mineCount;
    }

private:
    Ui::CustomDialog* ui;

    int rows = kMinCustomRows;
    int cols = kMinCustomRows;
    int mineCount = kMinCustomMineCount;

    void resetLineEdit(QLineEdit* lineEdit);

    void setRowsEditConnect();

    void setColsEditConnect();

    void setMineEditConnect();
};


#endif //MINESWEEPER_CUSTOM_DIALOG_H
