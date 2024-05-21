#include "mainwindow.h"
#include "input.h"
#include <QApplication>
#include <QVBoxLayout>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.setCentralWidget(new Input);
    window.setFixedSize(260,450);
    window.setStyleSheet("QWidget{background-color:black;}");
    window.show();
    return a.exec();
}
