#include "HumanB.hpp"
#include <iostream>
#include <string>

void    HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &_weapon)
{
    this->weapon = &_weapon;
}