
#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap( void ) : ClapTrap()
{
	this->_damage = 30;
	this->_hit = 100;
	this->_energy = 100;
	std::cout << "FragTrap " << this->_name << " Constructor" << std::endl;
}

FragTrap::FragTrap( const std::string name ) : ClapTrap( name )
{
	this->_damage = 30;
	this->_hit = 100;
	this->_energy = 100;
	std::cout << "FragTrap  " << this->_name << " Constructor" << std::endl;
}

FragTrap::FragTrap( const FragTrap & other ) : ClapTrap( other.getName() )
{
	*this = other;
	std::cout << "FragTrap " << this->_name << " Copy Constructor" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap " << this->_name << " Destructor" << std::endl;
}

FragTrap &	FragTrap::operator=( const FragTrap & other )
{
	if ( this != &other )
	{
		this->_name = other.getName();
		this->_hit = other.getHit();
		this->_energy = other.getEnergy();
		this->_damage = other.getDamage();
	}
	return ( *this );
}

void	FragTrap::highFivesGuys( void )
{
	if ( this->_hit == 0 )
		std::cout << "FragTrap " << this->_name << " can't ask something... He's dead !" << std::endl;
	else if ( this->_energy == 0 )
		std::cout << "FragTrap " << this->_name << " can't ask something... He hasn't energy !" << std::endl;
	else
	{
		std::cout << "FragTrap " << this->_name << " asked : \"Hey bro ! let's have a High Five !?\"" << std::endl;
		this->_energy--;
	}
}
