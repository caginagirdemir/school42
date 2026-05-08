#pragma once

#include <string>
#include <iostream>
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
        Fixed &operator=(const Fixed &src);
    
    // Comparison Operators
        bool operator>(Fixed fixed)const;
        bool operator<(Fixed fixed)const;
        bool operator>=(Fixed fixed)const;
        bool operator<=(Fixed fixed)const;
        bool operator==(Fixed fixed)const;
        bool operator!=(Fixed fixed)const;

    // Arithmetic Operators
        float operator+(Fixed fixed)const;
        float operator-(Fixed fixed)const;
        float operator*(Fixed fixed)const;
        float operator/(Fixed fixed)const;
    
    // pre-increment Operators
        Fixed operator++();
        Fixed operator--();

    // post-increment Operators
        Fixed operator++(int);
        Fixed operator--(int);

    // Public Methods
        float   toFloat(void)const;
        int     toInt(void)const;
        static Fixed &min(Fixed &first, Fixed &second);
        static const Fixed &min(Fixed const &first, Fixed const &second);
        static Fixed &max(Fixed &first, Fixed &second);
        static const Fixed &max(Fixed const &first, Fixed const &second);

    // Get functions
        int getRawBits(void)const;
    // Set functions
        void setRawBits(int const raw);

    private:
        int _fp_value;
        static const int _fract_bits;
};

// Overload for ostream
std::ostream &operator<<(std::ostream &o, Fixed const &fixed);