#include "Harl.hpp"

int main(int argc, char ** argv)
{
    std::string str;
    Harl harl;

    if (argc == 2)
        harl.complain(argv[1]);
    else
        std::cout << "Error: Too many or Too few arguments you entered." << std::endl;

    
    return 0;
}