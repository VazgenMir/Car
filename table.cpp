#include "table.h"
#include <QTableView>
#include <QHBoxLayout>
#include <QStandardItemModel>
Table::Table(int &num,QTableView *table){
    QHBoxLayout *layout = new QHBoxLayout(this);
    table->setStyleSheet("QTableView{border-width: 1px; border-style: solid;}");
    table->setFixedWidth(525);

    // Initialize the model with 3 rows and 3 columns
    QStandardItemModel *model = new QStandardItemModel();
    model->setRowCount(num);
    // Set headers (optional)
    model->setHorizontalHeaderLabels({"Make", "Year", "Color", "Price($)", "On sale"});
    //model->setVerticalHeaderLabels({"Row 1", "Row 2", "Row 3"});

    table->setModel(model);
    table->setDisabled(true);
    layout->addWidget(table);
}

