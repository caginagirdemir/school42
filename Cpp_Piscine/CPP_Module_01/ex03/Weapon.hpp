#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
public:
    const   std::string getType(void);
    void    setType(std::string);
    Weapon();
    Weapon(std::string _type);
private:
    std::string _type;
};

#endif