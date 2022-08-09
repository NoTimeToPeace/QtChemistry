#ifndef LOCATION_H
#define LOCATION_H
#include <QString>

class Location
{
private:
    QString town; // Город
    QString street; // Улица
    QString house; // Дом

public:
    Location();
    void setTown(QString);
    void setStreet(QString);
    void setHouse(QString);
    QString getTown();
    QString getStreet();
    QString getHouse();
    QString getAdress();
};

#endif // LOCATION_H
