#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    public:
        //Constructors
        ClapTrap();
        ClapTrap(std::string str);
        ClapTrap(const ClapTrap &trap);
        ClapTrap & operator = (const ClapTrap &trap);

        //Deconstructor
        ~ClapTrap();

        //member functions
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    protected:
        std::string name;
        float	health;
        float	energy;
        float	damage;

};

#endif