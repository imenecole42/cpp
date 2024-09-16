
#ifndef __CAT_HPP__ 
# define __CAT_HPP__ 
	
#include "Animal.hpp"
#include "Brain.hpp"

using std::string;

class Cat : public Animal
{
	public:

		Cat( void );
		Cat( const Cat & other );

		virtual	~Cat( void );

		Cat &	operator=( const Cat & other );

		Brain	*getBrain( void ) const;
		void	setBrain( const Brain *brain );

		virtual void	makeSound( void ) const;

	private:

		Brain	*_brain;

};

#endif
