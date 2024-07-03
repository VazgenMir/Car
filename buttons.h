#ifndef BUTTONS_H
#define BUTTONS_H
#include "QVBoxLayout"
#include "qtableview.h"
#include <QPushButton>
class Buttons : public QWidget
{
public:
    Buttons(QTableView *table);
    QPushButton* add_;
    QVBoxLayout* layout1;
    int num = 0;
    int last;
    QHBoxLayout* layout;
public slots:
    void Click(QTableView *table);
};

#endif // BUTTONS_H
