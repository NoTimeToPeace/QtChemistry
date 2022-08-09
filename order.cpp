#include "order.h"
#include "ui_order.h"
#include "global_settings.h"

extern global_settings *settings_screens;

Order::Order(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Order)
{
    ui->setupUi(this);

    row = 0;
    number_order = 0;

    model = new QStandardItemModel(this);

    QStringList horizontalHeader; // горизонтальная линия модели отображения товаров в корзине
    horizontalHeader.append("№");
    horizontalHeader.append("Наименование");
    horizontalHeader.append("Кол-во штук");
    horizontalHeader.append("Цена");
    horizontalHeader.append("Дата заказа");
    horizontalHeader.append("Дата доставки");
    horizontalHeader.append("Пункт выдачи");
    horizontalHeader.append("Дни выдачи");
    horizontalHeader.append("Время выдачи");
    horizontalHeader.append("Телефон");

    model->setHorizontalHeaderLabels(horizontalHeader);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(come_back()));
}

void Order::add_order(QVector <Goods*> value)
{
    for (int i = 0; i < value.size(); i++)
    {
        all_goods.push_back(value.value(i));

        item = new QStandardItem(value.value(i)->getNumber_Order());
        qDebug() << item->text();
        model->setItem(row, 0, item);

        item = new QStandardItem(value.value(i)->getName());
        qDebug() << item->text();
        model->setItem(row, 1, item);

        item = new QStandardItem(QString::number(value.value(i)->getQuantity()));
        qDebug() << item->text();
        model->setItem(row, 2, item);

        item = new QStandardItem(QString::number(value.value(i)->getPrice_Product()) + " ₽");
        qDebug() << item->text();
        model->setItem(row, 3, item);

        item = new QStandardItem(value.value(i)->getDate_Order().toString(QDateTime::currentDateTime().date().toString()));
        qDebug() << item->text();
        model->setItem(row, 4, item);

        item = new QStandardItem(value.value(i)->getDelivery_Date().toString(QDateTime::currentDateTime().date().toString()));
        qDebug() << item->text();
        model->setItem(row, 5, item);

        item = new QStandardItem(value.value(i)->getLocation().get_location());
        qDebug() << item->text();
        model->setItem(row, 6, item);

        item = new QStandardItem(value.value(i)->getLocation().get_work_day());
        qDebug() << item->text();
        model->setItem(row, 7, item);

        item = new QStandardItem(value.value(i)->getLocation().get_work_time());
        qDebug() << item->text();
        model->setItem(row, 8, item);

        item = new QStandardItem(value.value(i)->getLocation().get_phone());
        qDebug() << item->text();
        model->setItem(row, 9, item);

        row++;
    }
    value.clear();
    number_order++;
}

void Order::come_back()
{
    this->hide();
    settings_screens->menu_screen->show();
}

int Order::get_order()
{
    return number_order;
}

Order::~Order()
{
    delete ui;
}
