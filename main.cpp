#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("图片解密工具 v1.0");
    w.show();
    w.setWindowIcon(QIcon("logo.ico"));
    return a.exec();
}
