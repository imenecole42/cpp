
#include "Brain.hpp"
#include <iostream>

Brain::Brain( void )
{
	std::cout << "Brain Default Constructor" << std::endl;
}

Brain::Brain( const std::string type )
{
	for ( int i(0); i < 100; i++ )
		this->_ideas[i] = type;
	std::cout << "Brain Constructor" << std::endl;
}

Brain::Brain( const Brain & other )
{
	std::cout << "Brain copy Constructor" << std::endl;
	*this = other;
}

Brain::~Brain( void )
{
	std::cout << "Brain Default Destructor" << std::endl;
}

Brain &	Brain::operator=( const Brain & other )
{
	if ( this != &other )
		setIdeas( other.getIdeas() );
	return ( *this );
}

const std::string	*Brain::getIdeas( void ) const
{
	return ( this->_ideas );
}

void		Brain::setIdeas( const std::string *ideas )
{
	for ( int i(0); i < 100; i++ )
		this->_ideas[i] = ideas[i];
}
