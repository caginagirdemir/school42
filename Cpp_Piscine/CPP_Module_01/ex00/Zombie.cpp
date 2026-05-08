#include "Zombie.hpp"

void     Zombie::announce(void)
{
    std::cout << this->zombie_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie (std::string name)
{
    this->zombie_name = name;
}

Zombie::~Zombie(void) {
    std::cout << this->zombie_name << ": IM DYING FROM STARVING.." << std::endl;
}
