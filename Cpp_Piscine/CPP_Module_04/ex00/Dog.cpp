#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
}

Dog::Dog(const Dog &dog_ref)
{
	*this = dog_ref;
}

Dog & Dog::operator=(const Dog &dog_ref) {
	this->type = dog_ref.type;
	return *this;
}

Dog::~Dog() {
}

void Dog::makeSound() const
{
    std::cout << this->getType() << " makes Hav Hav Hav Sound " << std::endl;
}