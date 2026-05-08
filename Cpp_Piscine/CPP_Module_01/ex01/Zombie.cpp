#include "Zombie.hpp"

void    Zombie::announce (void)
{
    std::cout << this->z_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie (void) {}

Zombie::~Zombie (void)
{
    std::cout << this->z_name << ": I'm DYING STARVING..." << std::endl;
}

void    Zombie::set_name(std::string name)
{
    this->z_name = name;
}