#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
public:
    std::string name;
    Weapon      &weapon;
    void        attack();
    HumanA(std::string _name, Weapon &_weapon) : name(_name), weapon(_weapon) {};
};

#endif