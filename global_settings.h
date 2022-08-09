#ifndef GLOBAL_SETTINGS_H
#define GLOBAL_SETTINGS_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include <QString>
#include <QPixmap>
#include <QTime>
#include "menu.h"
#include "drug.h"
#include "drugstore.h"
#include "product.h"
#include "basket.h"
#include "order.h"
#include "analytics.h"

class global_settings
{

public:
    global_settings();
    void initializaton_screens(Menu*, Product*, Basket*, Order*, Analytics*);
    void download_products();
    void download_drugstores();

public:
    Menu *menu_screen; // Форма меню
    Product *product_screen; // Форма товара
    Basket *basket_screen; // Форма корзины
    Order *order_screen; // Форма заказа
    Analytics *analytics_screen; // Форма аналитики
    QVector <Drug*> drugs; // Все лекарства
    QVector <drugstore*> drugstores; // Все аптеки
    QDateTime start_time; // Время запуска приложения

};

#endif // GLOBAL_SETTINGS_H
