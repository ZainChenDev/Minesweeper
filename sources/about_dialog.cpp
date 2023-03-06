//
// Created by chest on 2023-03-03.
//

// You may need to build the project (run Qt uic code generator) to get "ui_about_dialog.h" resolved

#include "headers/about_dialog.h"
#include "ui_about_dialog.h"


AboutDialog::AboutDialog(QWidget* parent) :
        QDialog(parent), ui(new Ui::AboutDialog) {
    ui->setupUi(this);

    iconImage.load(":/resources/images/icon.png");

    setWindowTitle("About");

    connect(ui->quitBtn, &QPushButton::clicked, [this] {
        close();
    });

    ui->textBrowser->setOpenExternalLinks(true);
}

AboutDialog::~AboutDialog() {
    delete ui;
}

void AboutDialog::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    QRect rect(30, ui->textBrowser->y(), 70, 70);
    painter.drawPixmap(rect, iconImage);
}
