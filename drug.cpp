#include "drug.h"

Drug::Drug(QString _name, QString _composition, QString _description, QString _volume, QString _testimony, double _price, bool _recipe, QPixmap& _photo, QString _illness, int _first, int _second)
{
    name = _name;
    composition = _composition;
    description = _description;
    volume = _volume;
    testimony = _testimony;
    price = _price;
    recipe = _recipe;
    photo = _photo;
    illness = _illness;
    in_first_drugstore = _first;
    in_second_drugstore = _second;
}

void Drug::set_photo(QPixmap &value)
{
    photo = value;
}

void Drug::set_composition(QString value)
{
    composition = value;
}

void Drug::set_description(QString value)
{
    description = value;
}

void Drug::set_name(QString value)
{
    name = value;
}

void Drug::set_price(double value)
{
    price = value;
}

void Drug::set_recipe(bool value)
{
    recipe = value;
}

void Drug::set_testimony(QString value)
{
    testimony = value;
}

void Drug::set_volume(QString value)
{
    volume = value;
}

QString Drug::get_composition()
{
    return composition;
}

QString Drug::get_description()
{
    return description;
}

QString Drug::get_name()
{
    return name;
}

double Drug::get_price()
{
    return price;
}

bool Drug::get_recipe()
{
    return recipe;
}

QString Drug::get_illness()
{
    return illness;
}

QString Drug::get_testimony()
{
    return testimony;
}

QString Drug::get_volume()
{
    return volume;
}

QPixmap& Drug::get_photo()
{
    return photo;
}

void Drug::minus_in_first_drugstore(int value)
{
    if (in_first_drugstore > 0)
    {
        in_first_drugstore -= value;
    }
}

void Drug::minus_in_second_drugstore(int value)
{
    if (in_second_drugstore > 0)
    {
        in_second_drugstore -= value;
    }
}

void Drug::plus_in_first_drugstore()
{
    in_first_drugstore++;
}

void Drug::plus_in_second_drugstore()
{
    in_second_drugstore++;
}

int Drug::get_in_first_drugstore()
{
    return in_first_drugstore;
}

int Drug::get_in_second_drugstore()
{
    return in_second_drugstore;
}
