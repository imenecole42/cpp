#ifndef  HARL_HPP
# define  HARL_HPP

# include <string>

class Harl
{
	public:

	Harl( void );
	~Harl();
	void	complain( std::string level );

	private:

	void	(Harl::*_fct[5])( void );

	void	_debug( void );
	void	_info( void );
	void	_warning( void );
	void	_error( void );
	void	_msg( void );
};

#endif