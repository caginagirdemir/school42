#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
    public:
    //Constructors
        WrongAnimal();
        WrongAnimal(const WrongAnimal &copy);
    
    //Deconstructors
        ~WrongAnimal();
    
    //Overloaded Operators
        WrongAnimal &operator=(const WrongAnimal &src);

    //Public Methods
        void makeSound(void) const;
    
    //Get Funcs.
        std::string getType(void)const;

    protected:
        std::string _type;
};