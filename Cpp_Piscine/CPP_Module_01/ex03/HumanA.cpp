#include "HumanA.hpp"
#include <iostream>
#include <string>

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}