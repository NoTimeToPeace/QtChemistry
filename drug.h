#ifndef DRUG_H
#define DRUG_H
#include <QString>
#include <QVector>
#include <QPixmap>

class Drug
{
protected:
    QString composition; // состав лекарства
    QString description; // описание лекарства
    QString name; // название лекарства
    double price; // цена лекарства
    bool recipe; // нужен ли рецепт
    QString volume; // объём лекраства
    QString testimony; // показания к применения
    QString illness; // болезни, от которых лечат
    QPixmap photo; // фото лекарства
    int in_first_drugstore; // кол-во лекарств в первой аптеке
    int in_second_drugstore; // кол-во лекарств во второй аптеке

public:
    Drug(QString, QString, QString, QString, QString, double, bool, QPixmap&, QString, int, int); // конструктор с параметрами
    void set_composition(QString);
    void set_name(QString);
    void set_description(QString);
    void set_price(double);
    void set_recipe(bool);
    void set_volume(QString);
    void set_testimony(QString);
    void set_photo(QPixmap&);
    QString get_composition();
    QString get_name();
    QString get_description();
    double get_price();
    bool get_recipe();
    QString get_volume();
    QString get_testimony();
    QPixmap& get_photo();
    QString get_illness();
    int get_in_first_drugstore();
    int get_in_second_drugstore();
    void minus_in_first_drugstore(int);
    void minus_in_second_drugstore(int);
    void plus_in_first_drugstore();
    void plus_in_second_drugstore();
};

#endif // DRUG_H
