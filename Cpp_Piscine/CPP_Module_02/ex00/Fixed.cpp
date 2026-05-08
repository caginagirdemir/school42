#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() : _fp_value(0) //bu kullanim = this->_fp_value = 0 a karsilik geliyor
{
    std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::Fixed (const Fixed &copy)
{
    //this->_fp_value = copy._fp_value;
    //this->_fract_bits = copy._fract_bits;
    *this = copy;
    std::cout << "Fixed Copy Constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Fixed Deconstructor called" << std::endl;
}

Fixed &Fixed::operator =(const Fixed &src)
{
    if (this != &src) //kendi kendine atama yapmiyorsa
        this->_fp_value = src.getRawBits();
    std::cout << "Fixed Copy Assignment Constructor called" << std::endl;
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->_fp_value;
}

void    Fixed::setRawBits(int const raw)
{
    this->_fp_value = raw;
}
