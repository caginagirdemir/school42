#include "Weapon.hpp"
#include <iostream>
#include <string>

void    Weapon::setType(std::string _type)
{
    this->_type = _type;
}

const   std::string Weapon::getType(void)
{
    return this->_type;
}

Weapon::Weapon() {}

Weapon::Weapon(std::string _type)
{
    this->_type = _type;
}