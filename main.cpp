#include "mainwindows.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindows w;
    w.setMinimumSize(QSize(800,600));
    w.show();
    return a.exec();
}
