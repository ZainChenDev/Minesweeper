//
// Created by chest on 2023-03-03.
//

#ifndef MINESWEEPER_ABOUT_DIALOG_H
#define MINESWEEPER_ABOUT_DIALOG_H

#include <QDialog>
#include <QPainter>


QT_BEGIN_NAMESPACE
namespace Ui { class AboutDialog; }
QT_END_NAMESPACE

class AboutDialog : public QDialog {
Q_OBJECT

public:
    explicit AboutDialog(QWidget* parent = nullptr);

    ~AboutDialog() override;

    void paintEvent(QPaintEvent*) override;

private:
    Ui::AboutDialog* ui;

    QPixmap iconImage;
};


#endif //MINESWEEPER_ABOUT_DIALOG_H
