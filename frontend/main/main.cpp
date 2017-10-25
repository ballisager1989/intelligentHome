#include <iostream>

using namespace std;

//Frontend
#include "mainwindow.h"

//Qt
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    cout << "Hello World!" << endl;
    return app.exec();
}
