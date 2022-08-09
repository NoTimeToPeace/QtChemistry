#ifndef DRUGSTORE_H
#define DRUGSTORE_H

#include "location.h"

class drugstore
{
public:
    drugstore();
    void set_location(QString, QString, QString);
    QString get_location();
    QString get_work_time();
    QString get_work_day();
    QString get_phone();

public:
    Location location; // расположение аптеки
    QString work_time; // время работы
    QString phone; // номер для связи
    QString work_day; // дни работы

};

#endif // DRUGSTORE_H
