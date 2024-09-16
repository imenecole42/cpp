#include "Fixed.hpp"

Fixed::Fixed():_nbr(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}
Fixed::Fixed(const int nbr_int)
{
    std::cout<<"int constructed called"<<std::endl;
    this->_nbr=nbr_int<<this->_bit;
}
Fixed::Fixed(const float nbr_float)
{
    std::cout << "Float constructor called" << std::endl;
	this->_nbr = roundf( nbr_float * ( 1 << this->_bit) );
}
Fixed::Fixed(const Fixed &other)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this=other;
}
Fixed &	Fixed::operator=( const Fixed & other )
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    this->_nbr=other.getRawBits();
    return(*this);
}

float Fixed::toFloat( void ) const
{
	return ( ( float )this->_nbr / ( 1 << this->_bit ) );
}
int Fixed::toInt( void ) const
{
    return ( this->_nbr >> this->_bit );
}
//operateur 
int	Fixed::getRawBits(void) const
{
	return (this->_nbr);
}

void	Fixed::setRawBits( int nbr)
{
	this->_nbr = nbr;
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	return (this->toFloat() - other.toFloat());
}
Fixed	Fixed::operator*(Fixed const &other) const
{
	return (this->toFloat() * other.toFloat());
}
Fixed	Fixed::operator/(Fixed const &other) const
{
	return (this->toFloat() / other.toFloat());
}


bool	Fixed::operator>(Fixed const &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(Fixed const &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(Fixed const &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(Fixed const &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(Fixed const &other) const
{
	return (this->getRawBits() != other.getRawBits());
}


Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
   	++*this;
   return (temp);
}

Fixed	Fixed::operator--(int)
{
 	Fixed temp = *this;
   --*this;
   return (temp);
}

Fixed	&Fixed::operator++()
{
   ++this->_nbr;
   return (*this);
}

Fixed	&Fixed::operator--()
{
	--this->_nbr;
	return (*this);
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}
const Fixed Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b) ? a : b;
}
Fixed Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}
const Fixed Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b) ? a : b;
}
std::ostream &operator<<(std::ostream &out, Fixed const &other)
{
	out << other.toFloat();
	return out;
}