
#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) : _type( "" )
{
	std::cout << "Animal Default Constructor" << std::endl;
}

Animal::Animal( const Animal & other )
{
	std::cout << "Animal Copy Constructor" << std::endl;
	*this = other;
}

Animal::~Animal( void )
{
	std::cout << "Animal Destructor" << std::endl;
}

Animal &	Animal::operator=( const Animal & other )
{
	if ( this != &other )
		this->_type = other.getType();
	return ( *this );
}

std::string	Animal::getType( void ) const
{
	return ( this->_type );
}

void	Animal::setType( const std::string type )
{
	this->_type = type;
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal sound : \"...\" ( imagine make sound !! )" << std::endl;
}
