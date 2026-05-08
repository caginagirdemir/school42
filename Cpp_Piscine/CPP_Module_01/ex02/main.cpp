#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR;
    stringPTR = &str;
    std::string &stringREF = str;
    //tek bir atama yapilabilir referens adres değeri degistirilemez

    std::cout << str << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << stringREF << std::endl;

    return 0;
}
