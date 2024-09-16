#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <unistd.h>
class Fixed
{
    private:
        int _nbr;
        static const int _bit=8;
    public:
        Fixed(void);
        Fixed(const int nbr);
        Fixed(const float nbr );
        ~Fixed();
        Fixed(const Fixed &other);
		Fixed & operator=( const Fixed &other );
        int getRawBits( void ) const;
        void setRawBits( int nbr );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream & operator<<( std::ostream & out, Fixed const & other );
#endif
