#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
    public:
        void announce(void);
        //Zombie(std::string name);
        //default constructor without parameter
        Zombie(void);
        ~Zombie(void);
        void set_name(std::string name);
    private:
        std::string z_name;
};

Zombie  *hordeZombie(int N, std::string name);

#endif