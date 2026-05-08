#pragma once

#include <iostream>
#include <string>

class Animal
{
    public:
        // Constructors
        Animal();
        Animal(std::string);
        Animal(const Animal &animal_ref);
        Animal &operator=(const Animal &animal_ref);

        // Deconstructor
        virtual ~Animal();

        // Get function
        std::string getType() const;

        virtual void makeSound() const;

    protected:
        std::string type;

};