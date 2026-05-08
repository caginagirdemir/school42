#include "Harl.hpp"

int main()
{
    std::string str;
    Harl harl;
    while(1)
    {
        std::cout << "Type in Harl's complain [debug, info, warning, error]" <<  std::endl;
        while(str == "")
            std::getline(std::cin, str);
        if(str == "exit")
            break;
        harl.complain(str);
        str = "";
        std::cin.clear();
    }
    
    return 0;
}