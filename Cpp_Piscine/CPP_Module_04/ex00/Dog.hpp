#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{
    public:
    // Constructors
        Dog();
        Dog(const Dog &dog_ref);
        Dog &operator=(const Dog &dog_ref);

    // Deconstructor
        ~Dog();

    virtual void makeSound() const;
};