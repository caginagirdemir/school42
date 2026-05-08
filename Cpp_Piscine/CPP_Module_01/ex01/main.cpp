#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::string str = "test";
    Zombie *zombies = hordeZombie(N, str);
    for (int i = 0; i < N; i++)
        zombies[i].announce();
    delete [] zombies;
    return 0;
}