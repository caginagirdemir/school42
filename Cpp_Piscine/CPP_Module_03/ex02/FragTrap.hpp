#pragma once

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
    public:
        //contructors
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &flagtrap_ref);
        FragTrap & operator = (const FragTrap &flagtrap_ref);

        // //decontructor
        ~FragTrap();

        void highFivesGuys();


};
