#include "Harl.hpp"

void Harl::complain (std::string level)
{
    void (Harl::*p[4]) (void);
    int i;
    std::string str[] = {"debug", "info", "warning", "error"}; 

    p[0] = &Harl::debug;
    p[1] = &Harl::info;
    p[2] = &Harl::warning;
    p[3] = &Harl::error;
    for(i = 0; i < 4 && level != str[i]; i++)
        ;
    if (i == 4)
        return;
    while(i < 4)
    {
        (this->*(p[i]))();
        i++;
    }
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}
void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
}
void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}
void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}
