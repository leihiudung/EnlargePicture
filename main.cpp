//#include "mainwindow.h"
#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    widget w;
//    widget w;
//    MainWindow w;
//    a.installNativeEventFilter(&w);
    w.show();
    return a.exec();
}
