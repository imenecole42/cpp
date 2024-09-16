
#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog Default Constructor" << std::endl;
}

Dog::Dog( const Dog & other) : Animal()
{
	std::cout << "Dog copy Constructor" << std::endl;
	*this = other;
}

Dog::~Dog( void )
{
	std::cout << "Dog Default Destructor" << std::endl;
}

Dog &	Dog::operator=( const Dog & other)
{
	if ( this != &other)
		this->_type = other.getType();
	return ( *this );
}

void	Dog::makeSound( void ) const
{
	std::cout << "Whaaaaaaaaaf" << std::endl;
}
