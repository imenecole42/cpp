#include "Fixed.hpp"

Fixed::Fixed(): _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int nbr_int)
{
	std::cout << "int constructed called" << std::endl;
	this->_nbr = nbr_int << this->_bit;
}
Fixed::Fixed(const float nbr_float)
{
	std::cout << "Float constructor called" << std::endl;
	this->_nbr = roundf(nbr_float * (1 << this->_bit));
}
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_nbr = other.getRawBits();
	return (*this);
}
int Fixed ::getRawBits(void) const
{
	return (this->_nbr);
}
void Fixed::setRawBits(int nbr)
{
	this->_nbr = nbr;
}
float Fixed::toFloat(void) const
{
	return ((float)this->_nbr / (1 << this->_bit));
}
int Fixed::toInt(void) const
{
	return (this->_nbr >> this->_bit);
}
//ces opérateurs sont surchargés en tant que fonctions globales avec deux paramètres,
	//cout et objet de classe définie par l'utilisateur
//On retourne un « ostream » pour permettre l'enchaînement des opérations sur la sortie standard
std::ostream &operator<<(std::ostream &out, Fixed const &other)
{
	out << other.toFloat();
	return (out);
}
