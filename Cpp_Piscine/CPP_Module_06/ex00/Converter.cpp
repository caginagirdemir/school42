#include "Converter.hpp"
#include <limits>
#include <iostream>
#include <iomanip>

Converter::Converter() {};

Converter::Converter(Converter &copy) {
    this->str = copy.str;
}
Converter &Converter::operator=(Converter &assign) {
    (void)assign;
    return *this;
}
Converter::Converter(std::string str) {
    if (str == "nan" || str == "nanf") {
        this->str = str;
        return ;
    }
    if (str == "inf" || str == "+inf") {
        this->str = std::to_string(std::numeric_limits<double>::max());
        return ;
    }
    if (str == "-inf") {
        this->str = std::to_string(std::numeric_limits<double>::lowest());
        return ;
    }
    if (str == "+inff" || str == "inff") {
        this->str = std::to_string(std::numeric_limits<float>::max());
        return ;
    }
    if (str == "-inff") {
        this->str = std::to_string(std::numeric_limits<float>::lowest());
        return ;
    }
    if (str == "")
        throw(NotConvertable());
    if (str.length() == 1 && (str[0] < '0' || str[0] > '9'))
        str = std::to_string(int(str[0]));
    int signs = str[0] == '+' || str[0] == '-';
    int lastf = str[str.length() - 1] == 'f';
    int e = 0;
    int dotcount = 0;
    int numcount = 0;
    for (int i = 0; i < (int)str.length(); i++) {
        if (str[i] == 'e' && e == 0) {
            i++;
            if (i > 1 && i < (int)str.length() && (str[i] == '+' || str[i] == '-')) {
                e += 2;
                continue;
            }
        }
        if (str[i] == '.')
            dotcount++;
        if (str[i] >= '0' && str[i] <= '9')
            numcount++;
    }
    if (dotcount > 1 || str[str.length()-1] == '.' || str[0] == '.' || dotcount + numcount + lastf + signs + e != (int)str.length())
        throw(NotConvertable());
    this->str = str;
}

char Converter::getChar() const {
    if (this->str == "nan" || this->str == "nanf")
        throw(ImpossibleConversion());
    long double conv = std::stold(this->str);
    if (conv < std::numeric_limits<char>::lowest() || conv > std::numeric_limits<char>::max())
        throw(ImpossibleConversion());
    if (conv < 32)
        throw(NonDisplayable());
    return static_cast<char>(conv);
}

int Converter::getInt() const {
    if (this->str == "nan" || this->str == "nanf")
        throw(ImpossibleConversion());
    long double conv = std::stold(this->str);
    if (conv < std::numeric_limits<int>::lowest() || conv > std::numeric_limits<int>::max())
        throw(ImpossibleConversion());
    return static_cast<int>(conv);
}

float Converter::getFloat() const {
    if (this->str == "nan" || this->str == "nanf")
        return std::numeric_limits<float>::quiet_NaN();
    long double conv = std::stold(this->str);
    if (conv < std::numeric_limits<float>::lowest() || conv > std::numeric_limits<float>::max())
        throw(ImpossibleConversion());
    return static_cast<float>(conv);
}

double Converter::getDouble() const {
    if (this->str == "nan" || this->str == "nanf")
        return std::numeric_limits<double>::quiet_NaN();
    long double conv = std::stold(this->str);
    if (conv < std::numeric_limits<double>::lowest() || conv > std::numeric_limits<double>::max())
        throw(ImpossibleConversion());
    return static_cast<double>(conv);
}

void Converter::printChar() const {
    std::cout << "char: ";
    try {
        std::cout << this->getChar();
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

void Converter::printInt() const {
    std::cout << "int: ";
    try {
        std::cout << this->getInt();
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

void Converter::printFloat() const {
    std::cout << "float: ";
    try {
        std::cout << std::fixed << std::setprecision(1) << this->getFloat() << "f";
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

void Converter::printDouble() const {
    std::cout << "double: ";
    try {
        std::cout << std::fixed << std::setprecision(1) << this->getDouble();
    }
    catch (std::exception &e) {
        std::cout << e.what();
    }
    std::cout << std::endl;
}

const char *Converter::ImpossibleConversion::what(void) const throw()
{
	return ("impossible");
};

const char *Converter::NonDisplayable::what(void) const throw()
{
	return ("Non displayable");
};

const char *Converter::NotConvertable::what(void) const throw()
{
	return ("input is not Convertable");
};