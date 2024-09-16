
#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

#include <string>


class WrongAnimal
{
	public:

		WrongAnimal( void );
		WrongAnimal( const WrongAnimal & other );

		~WrongAnimal( void );

		WrongAnimal &	operator=( const WrongAnimal & other );

		std::string		getType( void ) const;
		void		setType( const std::string type );

		void		makeSound( void ) const;

	protected:

		std::string	_type;

};

#endif
