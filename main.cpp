#include "buttons.h"
#include "mainwindow.h"
#include "input.h"
#include <QApplication>
#include <QVBoxLayout>
void Insert();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    QWidget *central = new QWidget();
    QVBoxLayout* layout1 = new QVBoxLayout();
    QHBoxLayout* layout = new QHBoxLayout();
    layout1->addLayout(layout);
    //layout1->addWidget(new Input);
    central->setLayout(layout1);
    layout->addWidget(new Buttons());
    window.setCentralWidget(central);
    //window.setFixedSize(650,700);
    window.show();
    return a.exec();
}
void Insert(){

}
