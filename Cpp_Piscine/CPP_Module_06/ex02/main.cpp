#include "Classes.hpp"
#include <iostream>
#include <time.h>

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "A";
    if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "B";
    if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "C";
}

void identify(Base& p) {
    identify(&p);
}

Base *generate() {
    switch(rand()%3) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    Base base;
    for (int i = 0; i < 10; i++) {
        Base *random = generate();
        std::cout << "identify by pointer: ";
        identify(random);
        std::cout << "  identify by reference: ";
        identify(*random);
        std::cout << std::endl;
        delete random;
    }
    return 0;
}