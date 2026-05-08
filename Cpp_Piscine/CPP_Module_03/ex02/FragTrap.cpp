#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->name = "default fragtrap";
    this->health = 100;
    this->energy = 100;
    this->damage = 30;

    std::cout << this->name << " FragTrap created \n";
}

FragTrap::FragTrap(std::string _name)
{
    this->name = _name;
    this->health = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << this->name << " FragTrap created \n";
}

FragTrap::FragTrap(const FragTrap& fragtrap_ref) : ScavTrap()
{
    this->name = fragtrap_ref.name;
    this->health = fragtrap_ref.health;
    this->energy = fragtrap_ref.energy;
    this->damage = fragtrap_ref.damage;
    std::cout << this->name << " FragTrap created \n";
}

FragTrap & FragTrap::operator = (const FragTrap &fragtrap_ref)
{
    this->name = fragtrap_ref.name;
    this->health = fragtrap_ref.health;
    this->energy = fragtrap_ref.energy;
    this->damage = fragtrap_ref.damage;
    std::cout << this->name << " FragTrap created \n";
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << this->name << "FrapTrap destroyed\n";
}

void FragTrap::highFivesGuys()
{
    if(this->health == 0)
        std::cout << this->name << " I can't hight fives because is dead\n";
    else
        std::cout << this->name << " Hight five\n";
}
