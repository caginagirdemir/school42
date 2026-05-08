#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
}

Cat::Cat(const Cat &cat_ref)
{
	*this = cat_ref;
}

Cat & Cat::operator=(const Cat &cat_ref) {
	this->type = cat_ref.type;
	return *this;
}

Cat::~Cat() {
}

void Cat::makeSound() const
{
    std::cout << this->getType() << " makes Miav Miav Miav Sound " << std::endl;
}