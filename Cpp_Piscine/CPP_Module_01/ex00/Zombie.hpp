#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    public:
        void announce(void);
        //default contructor with parameter (new)
        Zombie(std::string name);
        //default destructor (delete)
        ~Zombie(void);
    
    private:
        std::string zombie_name;
};

#endif