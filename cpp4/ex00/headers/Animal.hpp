
#ifndef	__ANIMAL_HPP__
# define	__ANIMAL_HPP__

# include <string>


class Animal
{
	public:

		Animal( void );
		Animal( const Animal & other );

		virtual	~Animal( void );

		Animal &	operator=( const Animal & other );

		std ::string		getType( void ) const;
		void		setType( const std::string type );
	//Le virtual mot clé déclare une fonction virtuelle ou une classe de base virtuelle.
		virtual void		makeSound( void ) const;

	protected:

		std ::string	_type;

};

#endif
