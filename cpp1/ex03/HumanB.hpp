#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"
class HumanB
{
	private :
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB( std::string name);
		~HumanB( void );
		void setName( std::string name );
		std::string	getName( void ) const;
		void	attack( void ) const;
		void		setWeapon( Weapon &weapon );
};

#endif

