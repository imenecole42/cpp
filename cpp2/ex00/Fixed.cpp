#include "Fixed.hpp"
//constructeur intialition des objet
Fixed::Fixed() : _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}
//destructeur des objet(liber les espace des allocation)
Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return ( this->_nbr );
}

void	Fixed::setRawBits( int const nbr )
{
	this->_nbr = nbr;
}
// Declare copy constructor.
Fixed::Fixed( const Fixed &other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
// Declare copy assignment.
Fixed &Fixed::operator=( const Fixed &other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_nbr = other.getRawBits();
	return ( *this );
}

