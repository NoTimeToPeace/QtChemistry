#ifndef GOODS_H
#define GOODS_H
#include <QString>
#include <QDate>
#include <QRandomGenerator>
#include "drugstore.h"

class Goods
{
public:
    Goods(QString, int, double, double, QDate, QDate, drugstore*, QString);
    static QString generateOrder();
    QString getName();
    int getQuantity();
    double getPrice_Product();
    double getAll_Price();
    QDate getDelivery_Date();
    QString getNumber_Order();
    drugstore getLocation();
    QDate getDate_Order();
private:
    QString name; // название товара
    int quantity; // кол-во штук товара
    double price_product; // цена продукта
    double all_price; // общая цена
    QDate date_order; // дата заказа
    QDate delivery_date; // дата доставки
    drugstore *location; // пункт выдачи
    QString number_order; // номер заказа
};

#endif // GOODS_H
