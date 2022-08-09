#include "basket.h"
#include "ui_basket.h"
#include "global_settings.h"

extern global_settings *settings_screens;

Basket::Basket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Basket)
{
    ui->setupUi(this);

    pick_up_point();

    model = new QStandardItemModel(this);

    row = 0;

    QStringList horizontalHeader; // горизонтальная линия модели отображения товаров в корзине
    horizontalHeader.append("Товар");
    horizontalHeader.append("Цена");
    horizontalHeader.append("Кол-во штук");
    horizontalHeader.append("Общая стоимость");

    model->setHorizontalHeaderLabels(horizontalHeader);

    ui->tableView->setModel(model);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(come_back()));
    connect(ui->checkBox, SIGNAL(stateChanged(int)), this, SLOT(check_drugstore_1(int)));
    connect(ui->checkBox_2, SIGNAL(stateChanged(int)), this, SLOT(check_drugstore_2(int)));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(minus_product()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(delete_product()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(make_order()));
}

// формирование заказа
void Basket::make_order()
{
    // если не выбран пункт выдачи или нет товаров
    if ((!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked()) || row == 0)
    {
        return;
    }
    QVector <Goods*> products; // храним тут все продукты c заказа
    QRandomGenerator generator;
    generator.seed(QTime::currentTime().msec());
    QString number_order = Goods::generateOrder(); // номер заказа
    QDate delivery_date = QDate::currentDate().addDays(generator.generate() % 28 + 2); // дата доставки
    for (int i = 0; i < row; i++)
    {

        QString name = model->item(i, 0)->text();
        double price = model->item(i, 1)->text().toDouble();
        int quantity = model->item(i, 2)->text().toInt();
        for (int j = 0; j < settings_screens->drugs.size(); j++)
        {
            if (settings_screens->drugs.value(j)->get_name().toLower() == name.toLower())
            {
                if (ui->checkBox->isChecked())
                {
                    if (settings_screens->drugs.value(j)->get_in_first_drugstore() >= quantity)
                    {
                        settings_screens->drugs.value(j)->minus_in_first_drugstore(quantity);
                        break;
                    }
                    else
                    {
                        QMessageBox message;
                        message.setWindowTitle("Заказ не оформлен");
                        message.setText("Отсутствует товар на складе. Заказ не оформлен.");
                        message.exec();
                        return;
                    }
                }
                else
                {
                    if (settings_screens->drugs.value(j)->get_in_second_drugstore() >= quantity)
                    {
                        settings_screens->drugs.value(j)->minus_in_second_drugstore(quantity);
                        break;
                    }
                    else
                    {
                        QMessageBox message;
                        message.setWindowTitle("Заказ не оформлен");
                        message.setText("Отсутствует товар на складе. Заказ не оформлен.");
                        message.exec();
                        return;
                    }
                }
            }
        }
        drugstore *location = ui->checkBox->isChecked() ? settings_screens->drugstores.value(1) : settings_screens->drugstores.value(0);
        double all_price = price * quantity;
        Goods *product = new Goods(name, quantity, price, all_price, QDate::currentDate(), delivery_date, location, number_order);
        products.append(product);
    }
    QMessageBox message;
    message.setWindowTitle("Заказ № " + number_order + " оформлен");
    QString chemistry = ui->checkBox->isChecked() ? ui->label->text() : ui->label_2->text();
    message.setText("Дата заказа: " + QDateTime::currentDateTime().date().toString() + "\nКол-во товаров: " + ui->label_4->text() + "\nСумма заказа: "
                    + ui->label_6->text() + "\nПункт выдачи: " + chemistry + "\nДата доставки: " + delivery_date.toString(QDateTime::currentDateTime().date().toString()));
    message.exec();
    model->clear();
    row = 0;
    QStringList horizontalHeader; // горизонтальная линия модели отображения товаров в корзине
    horizontalHeader.append("Товар");
    horizontalHeader.append("Цена");
    horizontalHeader.append("Кол-во штук");
    horizontalHeader.append("Общая стоимость");
    model->setHorizontalHeaderLabels(horizontalHeader);
    how_many_price();
    how_many_products();
    emit send_order(products); // тут организовываем передачу заказа для его просмотра в форму заказа
}

// возврат назад
void Basket::come_back()
{
    this->hide();
    settings_screens->menu_screen->show();
}

// добавление товара в корзину
void Basket::add_to_basket(QString value)
{
    // если товар ранее был в корзине
    for (int i = 0; i < row; i++)
    {
        if (value == model->item(i, 0)->text())
        {
            // установили новое кол-во товара
            int data = model->item(i, 2)->text().toInt() + 1;
            model->item(i, 2)->setText(QString::number(data));
            // пересчитали стоимость товара
            double price = model->item(i, 1)->text().toDouble() * model->item(i, 2)->text().toInt();
            model->item(i, 3)->setText(QString::number(price));
            how_many_price();
            how_many_products();
            return;
        }
    }
    // если товара ранее не было в корзине
    for (int i = 0; i < settings_screens->drugs.size(); i++)
    {
        if (value == settings_screens->drugs.value(i)->get_name())
        {
            item = new QStandardItem(value);
            qDebug() << item->text();
            model->setItem(row, 0, item);
            item = new QStandardItem(QString::number(settings_screens->drugs.value(i)->get_price()));
            model->setItem(row, 1, item);
            item = new QStandardItem(QString("1"));
            model->setItem(row, 2, item);
            double price = model->item(row, 1)->text().toDouble() * model->item(row, 2)->text().toDouble();
            //qDebug() << price;
            item = new QStandardItem(QString::number(price));
            model->setItem(row, 3, item);
            row++;
            how_many_price();
            how_many_products();
            return;
        }
    }
}

void Basket::check_drugstore_1(int value)
{
    if (value == 2)
    {
        ui->checkBox_2->setEnabled(false);
    }
    else if (value == 0)
    {
        ui->checkBox_2->setEnabled(true);
    }
}

void Basket::check_drugstore_2(int value)
{
    if (value == 2)
    {
        ui->checkBox->setEnabled(false);
    }
    else if (value == 0)
    {
        ui->checkBox->setEnabled(true);
    }
}

// количество всех товаров
void Basket::how_many_products()
{
    int data = 0;
    for (int i = 0; i < row; i++)
    {
        data += model->item(i, 2)->text().toInt();
    }
    ui->label_4->setText(QString::number(data));
}

// сумма покупки
void Basket::how_many_price()
{
    double price = 0;
    for (int i = 0; i < row; i++)
    {
        price += model->item(i, 3)->text().toDouble();
    }
    ui->label_6->setText(QString::number(price) + " ₽");
}

// загрузка пунктов выдачи
void Basket::pick_up_point()
{
    ui->label->setText(settings_screens->drugstores.value(1)->get_location());
    ui->label_2->setText(settings_screens->drugstores.value(0)->get_location());
}

// удаление продукта
void Basket::delete_product()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (index.row() == -1 && index.column() == -1)
    {
        return;
    }
    model->removeRow(index.row());
    row--;
    how_many_price();
    how_many_products();
}

// уменьшение кол-ва продукта
void Basket::minus_product()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (index.row() == -1 && index.column() == -1)
    {
        return;
    }
    int quantity = model->item(index.row(), 2)->text().toInt(); // текущее кол-во товаров
    if (quantity == 1)
    {
        // вызов функции удаления строки и вычитание кол-ва строк в самой функции
        delete_product();
    }
    else
    {
        quantity--;
        model->item(index.row(), 2)->setText(QString::number(quantity));
        // пересчитываем стоимость товара
        double price = model->item(index.row(), 1)->text().toDouble() * model->item(index.row(), 2)->text().toInt();
        model->item(index.row(), 3)->setText(QString::number(price));
        how_many_price();
        how_many_products();
    }
}

Basket::~Basket()
{
    delete ui;
}
