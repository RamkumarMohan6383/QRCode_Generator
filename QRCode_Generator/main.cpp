#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <string>
#include <sstream>


string dec2hex(long a);
long hex2dec(const string & hexstr);
string hexadd(const string & hex1, const string & hex2);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Remove "?" Button from QDialog
    Qt::WindowFlags flags = Qt::Dialog;
    flags |= Qt::WindowCloseButtonHint;
    flags |= Qt::WindowMinimizeButtonHint;
    w.setWindowFlags(flags);


    w.show();

    return a.exec();
}


