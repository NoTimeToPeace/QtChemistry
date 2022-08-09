#include "analytics.h"
#include "ui_analytics.h"
#include "global_settings.h"

extern global_settings *settings_screens;

Analytics::Analytics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Analytics)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(come_back()));
}

void Analytics::come_back()
{
    this->hide();
    settings_screens->menu_screen->show();
}

void Analytics::refresh()
{
    double all_money = 0;
    int all_products = 0;
    QDateTime residance_time = QDateTime::currentDateTime();
    int first_apteka = 0;
    int second_apteka = 0;
    for (int i = 0; i < settings_screens->order_screen->all_goods.size(); i++)
    {
        all_money += settings_screens->order_screen->all_goods.value(i)->getAll_Price();
        all_products += settings_screens->order_screen->all_goods.value(i)->getQuantity();
        if (settings_screens->order_screen->all_goods.value(i)->getLocation().get_location() == settings_screens->drugstores.value(0)->get_location())
        {
            first_apteka++;
        }
        else
        {
            second_apteka++;
        }
    }

    ui->label_2->setText(QString::number(all_money) + " ₽");
    ui->label_6->setText(QString::number(all_products));
    ui->label_4->setText(QString::number(settings_screens->order_screen->get_order()));
    ui->label_10->setText(QTime(0,0).addSecs(settings_screens->start_time.secsTo(residance_time)).toString("hh:mm:ss"));
    if (first_apteka >= second_apteka)
    {
        if (first_apteka == 0)
        {
            return;
        }
        ui->label_8->setText(settings_screens->drugstores.value(0)->get_location());
    }
    else
    {
        ui->label_8->setText(settings_screens->drugstores.value(1)->get_location());
    }
}

Analytics::~Analytics()
{
    delete ui;
}
