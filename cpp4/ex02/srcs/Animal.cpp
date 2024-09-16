
#include "Animal.hpp"
#include <iostream>

Animal::Animal( void ) : _type( "" )
{
	std::cout << "Animal Default Constructor" << std::endl;
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
//membre makesound
