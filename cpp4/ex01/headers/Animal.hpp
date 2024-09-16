
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

		std::string		getType( void ) const;
		void		setType( const std::string type );

		virtual void		makeSound( void ) const;

	protected:

		std::string	_type;

};

#endif
