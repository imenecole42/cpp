
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat Default Constructor" << std::endl;
}

WrongCat::WrongCat( const WrongCat & other ) : WrongAnimal()
{
	std::cout << "WrongCat copy Constructor" << std::endl;
	*this = other;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat Default Destructor" << std::endl;
}

WrongCat &	WrongCat::operator=( const WrongCat & other )
{
	if ( this != &other )
		this->_type = other.getType();
	return ( *this );
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Miaaaaaaaaaou" << std::endl;
}
