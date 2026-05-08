 #pragma once

 #include <iostream>
 #include "Animal.hpp"

 class Cat : public Animal {
      public:
    // Constructors
        Cat();
        Cat(const Cat &cat_ref);
        Cat &operator=(const Cat &cat_ref);

    // Deconstructor
        ~Cat();

    virtual void makeSound() const;
 };