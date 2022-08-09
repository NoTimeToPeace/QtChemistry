#include "menu.h"
#include "ui_menu.h"
#include "global_settings.h"
#include <QDebug>

extern global_settings *settings_screens;

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    model_2 = new QStringListModel(this); // инициализируем вторую модель для поиска
    QStringList List;

    // Вывод всех товаров в QListView
    for(int i = 0; i < settings_screens->drugs.size(); i++)
    {
        List << settings_screens->drugs.value(i)->get_name();
    }
    model->setStringList(List);
    ui->listView->setModel(model);
    ui-> listView->setEditTriggers(QAbstractItemView::NoEditTriggers); // отключаем изменение названия в списке модели
    connect(ui->listView, &QListView::doubleClicked,  this,  &Menu::open_product);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(search()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(open_basket()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(open_order()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(open_analytics()));
}

// Получение названия товара и его дальнейшее открытие
void Menu::open_product()
{
    QString row = ui->listView->currentIndex().data().toString(); // получаем наименование индекса
    settings_screens->menu_screen->hide();
    emit download_product(row);
}

void Menu::open_basket()
{
    this->hide();
    settings_screens->basket_screen->show();
}

void Menu::open_order()
{
    this->hide();
    settings_screens->order_screen->show();
}

void Menu::open_analytics()
{
    this->hide();
    settings_screens->analytics_screen->show();
    emit refresh_statistic();
}

Menu::~Menu()
{
    delete ui;
}

bool Menu::find_sub(QString str, QString sub)
{
    int sum = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == sub[0] && (i + sub.size()) <= str.size())
        {
            for (int j = 0; j < sub.size(); j++)
            {
                if (str[i+j] == sub[j])
                {
                    sum++;
                }
            }
            if (sum == sub.size())
            {
                return true;
            }
            else
            {
                sum = 0;
            }
        }
    }
    return false;
}

void Menu::search()
{
    QString value = ui->textEdit->toPlainText();
    if (value.size() > 1)
    {
        for (int i = 0; i < settings_screens->drugs.size(); i++)
        {
            if (find_sub(settings_screens->drugs.value(i)->get_name().toLower(), value.toLower()))
            {
                QStringList List;
                List << settings_screens->drugs.value(i)->get_name();
                model_2->setStringList(List);
                ui->listView->setModel(model_2);
            }
            else if (find_sub(settings_screens->drugs.value(i)->get_testimony().toLower(), value.toLower()))
            {
                QStringList List;
                List << settings_screens->drugs.value(i)->get_name();
                model_2->setStringList(List);
                ui->listView->setModel(model_2);
            }
            else if(find_sub(QString::number(settings_screens->drugs.value(i)->get_price()), value))
            {
                QStringList List;
                List << settings_screens->drugs.value(i)->get_name();
                model_2->setStringList(List);
                ui->listView->setModel(model_2);
            }
        }
    }
    else
    {
        ui->listView->setModel(model);
    }
}
