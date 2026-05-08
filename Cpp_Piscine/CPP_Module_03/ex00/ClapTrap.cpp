#include "ClapTrap.hpp"

#include <iostream>
#include <string>

// Constructors
ClapTrap::ClapTrap() : name("Default") {
	std::cout << this->name << " ClapTrap created" << std::endl;
    this->health = 10;
    this->energy = 10;
    this->damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << this->name << " ClapTrap copy created" << std::endl;
	this->damage = copy.damage;
	this->energy = copy.energy;
	this->health = copy.health;
}

ClapTrap::ClapTrap(std::string name) : name(name) {
	std::cout << this->name << " ClapTrap created" << std::endl;
    this->health = 10;
    this->energy = 10;
    this->damage = 0;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << this->name << " ClapTrap destroyed" << std::endl;
}


// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &assign) {
	std::cout << "assign operator called\n";
	this->name = assign.name;
	this->damage = assign.damage;
	this->energy = assign.energy;
	this->health = assign.health;
	std::cout << this->name << " ClapTrap = " << assign.name << std::endl;
	return *this;
}

/// Member funcs
void ClapTrap::attack(const std::string& target) {
	if (this->health == 0)
		std::cout << this->name << " ClapTrap can't attack because is dead" << std::endl;
	else if (this->energy == 0)
		std::cout << this->name << " ClapTrap can't attack to " << target << "because out of energy" << std::endl;
	else {
		std::cout
		<< this->name << " ClapTrap attack " << target
		<< ", causing " << this->damage << " damage"
		<< std::endl;
		this->energy-=1;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->health == 0) {
		std::cout << this->name << " ClapTrap can't take damage because is dead" << std::endl;
		return ;
	}
	if (amount > this->health) {
		amount = this->health;
	}

	this->health -= amount;
	if (this->health > 0)
		std::cout << this->name << " ClapTrap has taken " << amount << " damage" << std::endl;
	else 
		std::cout << this->name << " ClapTrap has taken " << amount << " damage and die!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->health == 0)
	{
		std::cout << this->name << " ClapTrap can't be repaired because is dead" << std::endl;
		return ;
	}
	if (this->energy > 0) {
		this->health += amount;
		std::cout << this->name << " gets repaired and recovers " << amount << " amount of health, " << this->health << " is new health point!\n";
		this->energy-=1;
	} else {
		std::cout << this->name << " attempts to repair itself but has no energy left!\n";
	}
}