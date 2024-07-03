#include "buttons.h"
#include "input.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
Buttons::Buttons(QTableView *table) {

    layout1 = new QVBoxLayout(this);
    layout = new QHBoxLayout(this);
    add_ = new QPushButton("add",this);
    add_->setFixedSize(50,50);
    layout1->addLayout(layout);
    layout->addWidget(add_);
    connect(add_, &QPushButton::clicked, [this,table]() {
        Click(table);
    });
}
void Buttons::Click(QTableView *table){
    QWidget *wdg = new QWidget;
    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(new Input(num,last,wdg,layout1,table));
    last=num;
    num++;
    wdg->setLayout(lay);
    wdg->show();
    //layout1->addWidget(new Input(num,last));
}
