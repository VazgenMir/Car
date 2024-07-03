#include "buttons.h"
#include "mainwindow.h"
#include "input.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QTableView>
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
    QTableView *table = new QTableView();
    layout->addWidget(new Buttons(table));
    layout1->addWidget(table);
    window.setCentralWidget(central);
    //window.setFixedSize(650,700);
    window.show();
    return a.exec();
}
void Insert(){

}
