#include <QApplication>
#include <QStyleFactory>
#include "sources/headers/main_window.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));

    MainWindow w;
    w.show();
    return QApplication::exec();
}
