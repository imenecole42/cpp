#include "HumanA.hpp"
HumanA::HumanA(std::string name, Weapon &weapon):_name(name), _weapon(weapon)
{
	
}

HumanA::~HumanA()
{
	std ::cout << "HumanA destructor" <<std ::endl;
}
void HumanA::setName( std::string name )
{
	this->_name = name;
}
std::string	HumanA::getName( void ) const
{
	return (this->_name);
}
void	HumanA::attack( void ) const
{
	std::cout<<this->_name<< " attacks with their" << _weapon.getType();
	std::cout<<std ::endl;
}
