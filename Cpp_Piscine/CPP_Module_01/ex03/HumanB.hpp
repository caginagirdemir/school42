#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>


class HumanB
{
public:
    std::string name;
    Weapon      *weapon;
    void        attack();
    void        setWeapon(Weapon &_weapon);
    HumanB(std::string _name) : name(_name) {};
};

#endif