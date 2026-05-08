#include "ScavTrap.hpp"

#include <iostream>
#include <string>

// Constructors
ScavTrap::ScavTrap() {
    this->name = "Default";
	this->damage = 20;
	this->energy = 50;
	this->health = 100;

	std::cout << this->name << " ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap()
{
	this->name = copy.name;
	this->damage = copy.damage;
	this->energy = copy.energy;
	this->health = copy.health;
	std::cout << this->name << " ScavTrap copy created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
    this->name = name;
	this->damage = 20;
	this->energy = 50;
	this->health = 100;

	std::cout << this->name << " ScavTrap created" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << this->name << " ScavTrap destroyed" << std::endl;
}

// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign) {
	this->name = assign.name;
	this->damage = assign.damage;
	this->energy = assign.energy;
	this->health = assign.health;
	std::cout << this->name << " ScavTrap = " << assign.name << std::endl;
	return *this;
}

// Member Funcs
void    ScavTrap::guardGate() {
	if (this->health == 0)
		std::cout << this->name << " ScavTrap can't guard gate because is dead" << std::endl;
	else
		std::cout << this->name << " Now in Gate Keeper mode\n";
}

void ScavTrap::attack(const std::string& target) {
	if(this->health == 0)
		std::cout << this->name << " ScavTrap can't attack because is dead" << std::endl;
	else
	{
		std::cout
		<< this->name << " ScavTrap attack " << target
		<< ", causing " << this->damage << " damage"
		<< std::endl;
	}
}