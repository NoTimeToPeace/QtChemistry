#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include "product.h"
#include "basket.h"
#include "order.h"
#include "analytics.h"
// Здесь все экраны подключать

global_settings *settings_screens = new global_settings();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    settings_screens->download_drugstores(); // загружаем все аптеки в программу
    settings_screens->download_products(); // загружаем все товары в программу

    Menu *_menu_screen = new Menu();
    ui->gridLayout_2->addWidget(_menu_screen);

    Product *_product_screen = new Product();
    ui->gridLayout_2->addWidget(_product_screen);
    _product_screen->hide();

    Basket *_basket_screen = new Basket();
    ui->gridLayout_2->addWidget(_basket_screen);
    _basket_screen->hide();

    Order *_order_screen = new Order();
    ui->gridLayout_2->addWidget(_order_screen);
    _order_screen->hide();

    Analytics *_analytic_screen = new Analytics();
    ui->gridLayout_2->addWidget(_analytic_screen);
    _analytic_screen->hide();

    settings_screens->initializaton_screens(_menu_screen, _product_screen, _basket_screen, _order_screen, _analytic_screen);
    connect(_menu_screen, SIGNAL(download_product(QString)), _product_screen, SLOT(load_product(QString)));
    connect(_product_screen, SIGNAL(add_product(QString)), _basket_screen, SLOT(add_to_basket(QString)));
    connect(_basket_screen, SIGNAL(send_order(QVector <Goods*>)), _order_screen, SLOT(add_order(QVector <Goods*>)));
    connect(_menu_screen, SIGNAL(refresh_statistic()), _analytic_screen, SLOT(refresh()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

