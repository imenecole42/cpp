
#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal( void ) : _type( "" )
{
	std::cout << "WrongAnimal Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & other )
{
	std::cout << "WrongAnimal copy Constructor" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal Default Destructor" << std::endl;
}

WrongAnimal &	WrongAnimal::operator=( const WrongAnimal & other )
{
	if ( this != &other )
		this->_type = other.getType();
	return ( *this );
}

std::string	WrongAnimal::getType( void ) const
{
	return ( this->_type );
}

void	WrongAnimal::setType( const std::string type )
{
	this->_type = type;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal sound \"...\" ( imagine make sound !! )" << std::endl;
}
