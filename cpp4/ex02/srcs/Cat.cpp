
#include "Cat.hpp"
#include <iostream>

Cat::Cat( void ) : Animal()
{
	std::cout << "Cat Default Constructor" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain( "Cat" );
}

Cat::Cat( const Cat & other ) : Animal()
{
	std::cout << "Cat copy Constructor" << std::endl;
	this->_brain = NULL;
	*this = other;
}

Cat::~Cat( void )
{
	delete this->_brain;
	std::cout << "Cat Default Destructor" << std::endl;
}

Cat &	Cat::operator=( const Cat & other )
{
	if ( this != &other )
	{
		if ( this->_brain )
			delete this->_brain;
		this->_brain = new Brain( *(other.getBrain()) );
		this->_type = other.getType();
	}
	return ( *this );
}

Brain	*Cat::getBrain( void ) const
{
	return ( this->_brain );
}

void	Cat::setBrain( const Brain *brain )
{
	*(this->_brain) = *brain;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miaaaaaaaaaou" << std::endl;
}
