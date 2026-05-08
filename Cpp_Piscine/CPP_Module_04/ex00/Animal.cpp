#include "Animal.hpp"

// Constructors
Animal::Animal()
{
    this->type = "default";
    std::cout << "Default constructor" << std::endl;
}

Animal::Animal(std::string _type) {
	this->type = _type;
    std::cout << "Default constructor with parameter" << std::endl;
}

Animal::Animal(const Animal &animal_ref) {
	*this = animal_ref;
    std::cout << "Copy constructor" << std::endl;
}

// Operators
Animal & Animal::operator=(const Animal &animal_ref) {
	this->type = animal_ref.type;
	std::cout << "Copy assign constructor" << std::endl;
	return *this;
}

// Destructor
Animal::~Animal() {
	std::cout << "Animal destroyed" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Default Sound!!!" << std::endl;
}

