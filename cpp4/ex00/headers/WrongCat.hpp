
#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:

		WrongCat( void );
		WrongCat( const WrongCat & other );

		~WrongCat( void );

		WrongCat &	operator=( const WrongCat & rhs );

		void	makeSound( void ) const;

};

#endif
