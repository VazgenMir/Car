#include "button.h"
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <iostream>
#include <QLabel>
#include "input.h"
Button::Button(QLabel *label)
{
    QString ext[5][4]={{"AC","+/-","%","/"},{"7","8","9","x"},{"4","5","6","-"},{"1","2","3","+"},{"0",",","="}};
    QGridLayout* glayout = new QGridLayout(this);

    for(int i = 0; i<=3;i++){
        for(int j = 0;j<=3;j++){
            QPushButton* button = new QPushButton(ext[i][j],this);
            if(j==3){
            button->setStyleSheet("QPushButton{font-size:20px;background-color:orange;width:50px;height:50px;border-radius:25px;color:white}QPushButton::pressed{background-color:darkorange}");
            }else if(i==0){
            button->setStyleSheet("QPushButton{font-size:20px;background-color:darkgray;width:50px;height:50px;border-radius:25px;}QPushButton::pressed{background-color:gray}");
            }else{
            button->setStyleSheet("QPushButton{font-size:20px;background-color:#4f4f4f;width:50px;height:50px;border-radius:25px;color:white}QPushButton::pressed{background-color:#3f3f3f}");
            }
            glayout->addWidget(button,i,j,1,1);
            connect(button, &QPushButton::clicked, [this,label,button ]() {
                Click(label,button);
            });
        }
    }
    for(int j = 0;j<=2;j++){
        QPushButton* button = new QPushButton(ext[4][j],this);
        if(j==0){
        button->setStyleSheet("QPushButton{font-size:20px;background-color:#4f4f4f;width:50px;height:50px;border-radius:25px;color:white}QPushButton::pressed{background-color:#3f3f3f}");
        glayout->addWidget(button,4,j,1,2);
        connect(button, &QPushButton::clicked, [this,label,button ]() {
            Click(label,button);
        });
        }else{
            if(j==1){
                button->setStyleSheet("QPushButton{font-size:20px;background-color:#4f4f4f;width:50px;height:50px;border-radius:25px;color:white}QPushButton::pressed{background-color:#3f3f3f}");
            }else{
                button->setStyleSheet("QPushButton{font-size:20px;background-color:orange;width:50px;height:50px;border-radius:25px;color:white}QPushButton::pressed{background-color:darkorange}");
            }
        glayout->addWidget(button,4,j+1,1,1);
        connect(button, &QPushButton::clicked, [this,label,button ]() {
            Click(label,button);
        });
        }
    }



}
void Button::Click(QLabel *label, QPushButton* button){
   // QPushButton *button = qobject_cast<QPushButton *> ( sender() );

    if(button->text().toStdString()=="+" ||button->text().toStdString()=="-"||button->text().toStdString()=="/"||button->text().toStdString()=="x"){
        label->setText(label->text().replace(",","."));
        num1 = label->text().toFloat();
        label->setText("");
        if(button->text().toStdString()=="+"){
            op = 1;
        }else if(button->text().toStdString()=="-"){
            op = 2;
        }else if(button->text().toStdString()=="/"){
            op = 3;
        }else{
            op = 4;
        }
        std::cout << num1 <<std::endl;
    }else if(button->text().toStdString()=="AC"){
        label->setText("0");
        num1 = 0;
    }else if(button->text().toStdString()=="+/-" ){
        if(label->text().contains("-")){
            label->setText(label->text().replace("-",""));

        }else{
            label->setText("-"+label->text());
        }
    }else if(button->text().toStdString()=="="){
        label->setText(label->text().replace(",","."));
        float eq;
        if(op == 1){
            std::cout << label->text().toFloat() << std::endl;
            eq = num1+label->text().toFloat();
         }else  if(op == 2){
            eq = num1-label->text().toFloat();
         }else  if(op == 3){
            eq = num1/label->text().toFloat();
         }else{
                eq = num1*label->text().toFloat();
        }
        label->setText(QString::number(eq));
        label->setText(label->text().replace(".",","));
    }else if(button->text().toStdString()=="%"){
            label->setText(QString::number(label->text().toFloat()/100));
    }else if(button->text()==","){
        if (not label->text().contains(",")){
        label->setText(label->text()+button->text());
        }
    }else{
        if(label->text()=="0"){
            label->setText("");
        label->setText(label->text()+button->text());
    }else{
            label->setText(label->text()+button->text());
        }
    }
//std::cout << button->text().toStdString() << std::endl;

}
