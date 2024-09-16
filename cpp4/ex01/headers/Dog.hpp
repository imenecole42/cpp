
#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
	public:

		Dog( void );
		Dog( const Dog & other );

		virtual	~Dog( void );

		Dog &	operator=( const Dog & other );

		Brain	*getBrain( void ) const;
		void	setBrain( const Brain *brain );

		virtual void	makeSound( void ) const;

	private:

		Brain	*_brain;
};

#endif
