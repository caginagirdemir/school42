#pragma once

#include <iostream>
#include <bitset>
#include <cmath>

class Fixed
{
    public:
    // Constructors
        Fixed();
        Fixed(const int input);
        Fixed(const float input);
        Fixed(const Fixed& copy);

    // Deconstructors
        ~Fixed();
    
    // Overloaded Operators
        Fixed &operator=(const Fixed &ref);
    
    // Public Methods
        float   toFloat(void) const;
        int     toInt(void)const;
    // Get functions
        int getRawBits(void)const;
    // Set functions
        void setRawBits(int const raw);

    private:
        int _fp_value;
        static const int _fract_bits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);