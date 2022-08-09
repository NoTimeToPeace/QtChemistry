#include "goods.h"

Goods::Goods(QString _name, int _quantity, double _price_product, double _all_price, QDate _date_order, QDate _delivery_date, drugstore *_location, QString _number_order)
{
    name = _name;
    quantity = _quantity;
    price_product = _price_product;
    all_price = _all_price;
    date_order = _date_order;
    delivery_date = _delivery_date;
    location = _location;
    number_order = _number_order;
}

QString Goods::generateOrder()
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = 12; // assuming you want random strings of 12 characters
    QString randomString;
    QTime midnight(0, 0, 0);
    for(int i=0; i<randomStringLength; ++i)
    {
        int index = QRandomGenerator::global()->generate() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}

QString Goods::getName()
{
    return name;
}

int Goods::getQuantity()
{
    return quantity;
}

double Goods::getPrice_Product()
{
    return price_product;
}

double Goods::getAll_Price()
{
    return all_price;
}

QDate Goods::getDate_Order()
{
    return date_order;
}

QDate Goods::getDelivery_Date()
{
    return delivery_date;
}

drugstore Goods::getLocation()
{
    return *location;
}

QString Goods::getNumber_Order()
{
    return number_order;
}
