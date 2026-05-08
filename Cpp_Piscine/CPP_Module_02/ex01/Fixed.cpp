#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

// Constructors
Fixed::Fixed(): _fp_value(0)
{
    std::cout << "Fixed Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
    std::cout << "Fixed Copy Constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
    std::bitset<32> x;
    x = this->_fp_value;
    std::cout << x << std::endl;
    this->_fp_value = input; //  << this->_fract_bits;
    x = this->_fp_value;
    std::cout << x << std::endl;
    std::cout << "Fixed Int Constructor called" << std::endl;
}

Fixed::Fixed(const float input)
{
    this->_fp_value = roundf(input * (1 << this->_fract_bits));
    std::cout << "Fixed Float Constructor called" << std::endl;
}

// Deconstructors
Fixed::~Fixed()
{
    std::cout << "Fixed Deconstructor called" << std::endl;
}

// Overloaded Operators
Fixed &Fixed::operator=(const Fixed &src)
{
    if (this != &src)
        this->_fp_value = src.getRawBits();
    
    std::cout << "Fixed Assignation operator called" << std::endl;
    return *this;
}

// Public Methods
float	Fixed::toFloat(void)const
{
	return ((float)this->_fp_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_fp_value >> this->_fract_bits);
}

// Get functions
int	Fixed::getRawBits(void)const
{
	return (this->_fp_value);
}

// Set functions
void	Fixed::setRawBits(int const raw)
{
	this->_fp_value = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
