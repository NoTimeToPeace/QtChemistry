#ifndef PRODUCT_H
#define PRODUCT_H

#include <QWidget>
#include <QString>
#include "drugstore.h"

namespace Ui {
class Product;
}

class Product : public QWidget
{
    Q_OBJECT

signals:
    void add_product(QString value);

public:
    explicit Product(QWidget *parent = nullptr);
    ~Product();

public slots:
    void load_product(QString value);
    void come_back();
    void add_product_in_basket();

private:
    Ui::Product *ui;
};

#endif // PRODUCT_H
