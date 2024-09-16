
#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"


class Dog : public Animal
{
	public:

		Dog( void );
		Dog( const Dog & other );

		virtual	~Dog( void );

		Dog &	operator=( const Dog & other );

		virtual void	makeSound( void ) const;
};

#endif
