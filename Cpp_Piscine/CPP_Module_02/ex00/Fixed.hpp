#include <iostream>

//Header-protection
//ifndef - define - endif yerine -> pragma once
#pragma once

#include <iostream>

class Fixed
{

    public:
    // Default Constructor
        Fixed();
    // Copy Default Constructor
        Fixed(const Fixed& copy);
    // Overloaded Operators
        Fixed &operator=(const Fixed &src);
    // Deconstructors
        ~Fixed();
    
    private:
        int _fp_value;
        static const int _fract_bits;

    
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};