#ifndef BUTTONS_H
#define BUTTONS_H
#include "QVBoxLayout"
#include <QPushButton>
class Buttons : public QWidget
{
public:
    Buttons();
    QPushButton* add_;
    QVBoxLayout* layout1;
    int num = 1;
    int last;
public slots:
    void Click();
};

#endif // BUTTONS_H
