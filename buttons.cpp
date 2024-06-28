#include "buttons.h"
#include "input.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
Buttons::Buttons() {

    layout1 = new QVBoxLayout(this);
    QHBoxLayout* layout = new QHBoxLayout(this);
    add_ = new QPushButton("add",this);
    add_->setFixedSize(50,50);
    layout1->addLayout(layout);
    layout->addWidget(add_);
    connect(add_, &QPushButton::clicked, [this]() {
        Click();
    });
}
void Buttons::Click(){
    layout1->addWidget(new Input(num,last));
    last=num;
    num++;
}
