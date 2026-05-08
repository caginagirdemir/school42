#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie *new_zombie = new Zombie(name);
    return (new_zombie);
}

void randomChump(std::string name)
{
    Zombie  zombie(name);
    zombie.announce();
}

int main()
{
    std::string name1, name2;
    std::cin >> name1 >> name2;
    Zombie *zombie_1 = newZombie(name1);
    randomChump(name2);
    zombie_1->announce();
    delete zombie_1;
    return 0;
}