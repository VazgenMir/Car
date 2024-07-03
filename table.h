#ifndef TABLE_H
#define TABLE_H
#include <QTableView>
#include <QStandardItemModel>
#include <QWidget>
class Table : public QWidget
{
public:
    Table(int &num, QTableView *table);
    //QStandardItemModel *model;
};

#endif // TABLE_H
