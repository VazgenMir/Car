#ifndef INPUT_H
#define INPUT_H
#include <QWidget>
#include "QLineEdit"
#include "QLabel"
#include "QHBoxLayout"
#include "qtableview.h"
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>

class Input : public QWidget
{
public:
    Input(int& num, int& last, QWidget *wdg, QLayout *layout1,QTableView *table);
    QLineEdit *text1;
    QComboBox *text;
    QLineEdit *text2;
    QLineEdit *text3;
    QLabel* label;
    QLabel* label1;
    QLabel* label2;
    QLabel* label3;
    QLabel* label4;
    QLabel* label5;
    QCheckBox* check;
    QPushButton* delete_;
    QPushButton* ok;
    QHBoxLayout* layout;
    QString inf;
public slots:
    void Click(int &num,int &last);
public slots:
    void Click1(QWidget *wdg, QLayout *layout1, int &num, int &last,QTableView* table);
};

#endif // INPUT_H
