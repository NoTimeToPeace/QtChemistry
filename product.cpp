#include "product.h"
#include "ui_product.h"
#include "global_settings.h"
#include "menu.h"
#include <QDebug>

extern global_settings *settings_screens;

Product::Product(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Product)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(come_back()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(add_product_in_basket()));
}

void Product::load_product(QString value)
{
    for (int i = 0; i < settings_screens->drugs.size(); i++)
    {
        if (settings_screens->drugs.value(i)->get_name() == value)
        {
            ui->label_3->setText(value); // название
            ui->label->setPixmap(settings_screens->drugs.value(i)->get_photo()); // фото
            ui->label_7->setText(settings_screens->drugs.value(i)->get_description()); // описание
            ui->label_21->setText(settings_screens->drugs.value(i)->get_composition()); // состав
            ui->label_8->setText(settings_screens->drugs.value(i)->get_volume()); // объём
            ui->label_9->setText(settings_screens->drugs.value(i)->get_testimony()); // показания
            ui->label_10->setText(settings_screens->drugs.value(i)->get_recipe()?"+":"-"); // рецепт
            ui->label_19->setText(settings_screens->drugs.value(i)->get_illness()); // болезни
            ui->label_12->setText(QString::number(settings_screens->drugs.value(i)->get_price()) + " ₽"); // цена
            ui->label_16->setText(QString::number(settings_screens->drugs.value(i)->get_in_first_drugstore())); // кол-во товаров в первой аптеке
            ui->label_17->setText(QString::number(settings_screens->drugs.value(i)->get_in_second_drugstore())); // кол-во товаров во второй аптеке
            break;
        }
    }
    settings_screens->product_screen->show();
}

void Product::come_back()
{
    this->hide();
    settings_screens->menu_screen->show();
}

void Product::add_product_in_basket()
{
    emit add_product(ui->label_3->text());
}

Product::~Product()
{
    delete ui;
}
