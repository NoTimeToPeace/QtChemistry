#include "drugstore.h"

drugstore::drugstore()
{

}

void drugstore::set_location(QString town, QString street, QString house)
{
    location.setTown(town);
    location.setStreet(street);
    location.setHouse(house);
}

QString drugstore::get_location()
{
    QString loc;
    loc = location.getTown() + ", " + location.getStreet() + ", " + location.getHouse();
    return loc;
}

QString drugstore::get_work_time()
{
    return work_time;
}

QString drugstore::get_work_day()
{
    return work_day;
}

QString drugstore::get_phone()
{
    return phone;
}
