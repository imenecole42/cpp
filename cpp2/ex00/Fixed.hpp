
#ifndef FIXED_HPP
#define FIXED_HPP
#include <stdio.h>
#include <iostream>


class Fixed
{
    private:
        int _nbr;
        static const int _bit=8; 
    public:
        Fixed();
        ~Fixed();
        // Declare copy constructor.
        Fixed(Fixed const &other);
        //opérateur d'assignation de copie canonique
        Fixed &operator=(Fixed const &other);
        int getRawBits( void ) const;
        void setRawBits( int const nbr ); 
};
#endif