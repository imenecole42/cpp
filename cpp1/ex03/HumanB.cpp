#include "HumanB.hpp"
HumanB::HumanB(std::string name)
{
	this->_weapon = NULL;
	this->_name = name;
}

HumanB::~HumanB()
{
	std ::cout << "HumanB destructor" << std::endl;
}
void HumanB::setName( std::string name )
{
	this->_name = name;
}
std::string	HumanB::getName( void ) const
{
	return (this->_name);
}

void	HumanB::setWeapon( Weapon &weapon )
{
		this->_weapon = &weapon;
}
void	HumanB::attack( void ) const
{

	if (!this->_weapon)
	{
		std ::cout << this->_name << " attacks with their " << this->_weapon->getType();
		return;
	}
	//pour jim attacks
	std ::cout << this->_name << " attacks with their " << this->_weapon->getType();
	std ::cout << std ::endl;
}

