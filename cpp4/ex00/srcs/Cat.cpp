
#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat Default Constructor" << std::endl;
}

Cat::Cat( const Cat & other ) : Animal()
{
	std::cout << "Cat copy Constructor" << std::endl;
	*this = other;
}

Cat::~Cat( void )
{
	std::cout << "Cat Default Destructor" << std::endl;
}

Cat &	Cat::operator=( const Cat & other )
{
	if ( this != &other )
		this->_type = other.getType();
	return ( *this );
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miaaaaaaaaaou" << std::endl;
}
