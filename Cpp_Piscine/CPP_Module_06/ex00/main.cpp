#include "Converter.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc != 2)
        return 0;
    Converter *conv;
    try {
        conv = new Converter(std::string(argv[1]));
    }
    catch(std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    conv->printChar();
    conv->printInt();
    conv->printFloat();
    conv->printDouble();
    delete conv;
    return 0;
}