#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct = ClapTrap();
    ClapTrap _ct = ClapTrap("default");
    ct = _ct;
    
    ct.takeDamage(4);
    ct.takeDamage(5);
    ct.beRepaired(20);
    ct.takeDamage(3);
    ct.takeDamage(3);
    
    ct.attack("default");
    return 0;
}