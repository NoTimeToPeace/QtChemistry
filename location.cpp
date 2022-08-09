#include "location.h"

Location::Location()
{

}

void Location::setHouse(QString value)
{
    house = value;
}

void Location::setTown(QString value)
{
    town = value;
}

void Location::setStreet(QString value)
{
    street = value;
}

QString Location::getHouse()
{
    return house;
}

QString Location::getTown()
{
    return town;
}

QString Location::getStreet()
{
    return street;
}
