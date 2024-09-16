
#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

using std::string;

class WrongCat : public WrongAnimal
{
	public:

		WrongCat( void );
		WrongCat( const WrongCat & other );

		~WrongCat( void );

		WrongCat &	operator=( const WrongCat & other );

		void	makeSound( void ) const;

};

#endif
