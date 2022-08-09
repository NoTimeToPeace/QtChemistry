#ifndef ORDER_H
#define ORDER_H

#include <QWidget>
#include <QVector>
#include <QStandardItemModel>
#include "goods.h"

namespace Ui {
class Order;
}

class Order : public QWidget
{
    Q_OBJECT

public:
    explicit Order(QWidget *parent = nullptr);
    QVector <Goods*> all_goods;
    int get_order();
    ~Order();

public slots:
    void add_order(QVector <Goods*>);
    void come_back();

private:
    Ui::Order *ui;
    QStandardItemModel *model; // модель отображения товаров в корзине
    QStandardItem *item;
    int row;
    int number_order;
};

#endif // ORDER_H
