
#include "Dog.hpp"
#include <iostream>

Dog::Dog( void ) : Animal()
{
	std::cout << "Dog Default Constructor" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain( "Dog" );
}

Dog::Dog( const Dog &other ) : Animal()
{
	std::cout << "Dog copy Constructor" << std::endl;
	this->_brain = NULL;
	*this =other;
}

Dog::~Dog( void )
{
	delete this->_brain;
	std::cout << "Dog Default Destructor" << std::endl;
}

Dog &	Dog::operator=( const Dog &other )
{
	if ( this != &other )
	{
		if ( this->_brain )
			delete this->_brain;
		this->_brain = new Brain( *(other.getBrain()) );
		this->_type =other.getType();
	}
	return ( *this );
}

Brain	*Dog::getBrain( void ) const
{
	return ( this->_brain );
}

void	Dog::setBrain( const Brain *brain )
{
	*(this->_brain) = *brain;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Whaaaaaaaaaf" << std::endl;
}
