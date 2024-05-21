#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QLabel>
#include "input.h"
#include <QPushButton>

class Button : public QWidget
{
public:
    Button(QLabel* label);
    float num1 = 0;
    int op = 0;
    QPushButton* button_press;
public slots:
void Click(QLabel *label, QPushButton *button);
};

#endif // BUTTON_H
