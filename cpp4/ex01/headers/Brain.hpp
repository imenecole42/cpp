
#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

# include <string>


class Brain
{
	public:

		Brain( void );
		Brain( const std::string type );
		Brain( const Brain & other );

		~Brain( void );

		Brain &	operator=( const Brain & other );

		const std::string	*getIdeas( void ) const;
		void			setIdeas( const std::string *ideas );

	private:

		std ::string	_ideas[100];
};

#endif
