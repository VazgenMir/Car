#include "input.h"
#include "qtableview.h"
#include "table.h"
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIntValidator>
#include <QPushButton>

Input::Input(int &num, int &last, QWidget *wdg = 0, QLayout *layout1 = 0, QTableView *table = 0)
{
layout = new QHBoxLayout(this);
    //delete_ = new QPushButton("X",this);
    ok = new QPushButton("OK",this);
    check = new QCheckBox(this);
    text1 = new QLineEdit(this);
    text2 = new QLineEdit(this);
    text3 = new QLineEdit(this);
    text = new QComboBox(this);
    label = new QLabel(this);
    label1 = new QLabel(this);
    label2 = new QLabel(this);
    label3 = new QLabel(this);
    label4 = new QLabel(this);
    label5 = new QLabel(this);
    label->setText(QString::number(num));
    inf = QString::number(num);
    layout->addWidget(label);
    layout->addWidget(label1);
    layout->addWidget(text);
    layout->addWidget(label2);
    layout->addWidget(text1);
    layout->addWidget(label3);
    layout->addWidget(text2);
    layout->addWidget(label4);
    layout->addWidget(text3);
    layout->addWidget(label5);
    layout->addWidget(check);
    //layout->addWidget(delete_);
    layout->addWidget(ok);
    label1->setText("Make:");
    text->setFixedSize(80,20);
    text->setStyleSheet("QLineEdit{font-size:10px;}");
    text1->setFixedSize(80,20);
    text1->setStyleSheet("QLineEdit{font-size:10px;}");
    text1->setValidator( new QIntValidator(1800, 2024, this) );
    text->addItem("BMW");
    text->addItem("Mercedes");
    text->addItem("Toyota");
    text->addItem("Tesla");
    label2->setText("Year:");
    label3->setText("Color:");
    label4->setText("Price($):");
    label5->setText("On sale:");
    text2->setFixedSize(80,20);
    text2->setStyleSheet("QLineEdit{font-size:10px;}");
    text3->setFixedSize(80,20);
    text3->setStyleSheet("QLineEdit{font-size:10px;}");
    text3->setValidator( new QIntValidator(0, 10000000, this) );
    connect(delete_, &QPushButton::clicked, [this,&num,&last]() {
        Click(num,last);
    });
    connect(ok, &QPushButton::clicked, [this,wdg,layout1,&num,&last,table]() {
        Click1(wdg,layout1,num,last,table);
    });

}
void Input::Click(int &num,int &last){

if(inf == QString::number(last)){
        last--;
    num--;
}
    for(int i = 0;i<=11;i++){
        QLayoutItem* item = layout->takeAt(0);
        delete item->widget();

    }
}
void Input::Click1(QWidget *wdg,QLayout *layout1,int &num,int &last,QTableView *table){
    wdg->hide();
    layout1->addWidget(new Table(num,table));
}
