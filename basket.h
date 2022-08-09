#ifndef BASKET_H
#define BASKET_H

#include <QWidget>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QDate>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include "goods.h"

namespace Ui {
class Basket;
}

class Basket : public QWidget
{
    Q_OBJECT

signals:
    void send_order(QVector <Goods*>);

public:
    explicit Basket(QWidget *parent = nullptr);
    ~Basket();

public slots:
    void come_back();
    void add_to_basket(QString); // добавление товара в корзину
    // для выбора одной аптеки доставки
    void check_drugstore_1(int);
    void check_drugstore_2(int);
    // уменьшение кол-ва товара и удаление
    void minus_product();
    void delete_product();
    // формирование заказа
    void make_order();

private:
    Ui::Basket *ui;
    //int all_products; // кол-во товаров в корзине
    //double all_price; // стоимость корзины
    QStandardItemModel *model; // модель отображения товаров в корзине
    QStandardItem *item;
    int row; // текущее кол-во строк в корзине

private:
    void how_many_products();
    void how_many_price();
    void pick_up_point(); // пункты выдачи

};

#endif // BASKET_H
