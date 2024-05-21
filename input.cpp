#include "input.h"
#include "button.h"
#include <QLabel>
#include <QVBoxLayout>
Input::Input()
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    label = new QLabel(this);
    layout->addWidget(label);
    label->setText("0");
    label->setAlignment(Qt::AlignRight);
    label->setFixedSize(225,60);
    label->setStyleSheet("QLabel{color:white;width:100px;height:10px;font-size:50px;}");
    layout->addWidget(new Button(label));
}
