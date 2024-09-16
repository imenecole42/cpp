#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name(""), _hit(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap " << this->_name << " Default constructer" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hit(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructer name " << std::endl;
}

ClapTrap ::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " Destructeur" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap " << this->_name << " copy constructer" << std::endl;
}

ClapTrap &ClapTrap ::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hit = other.getHit();
		this->_energy = other.getEnergy();
		this->_damage = other.getDamage();
	}
	return (*this);
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}
unsigned int ClapTrap::getHit(void) const
{
	return (this->_hit);
}
unsigned int ClapTrap::getEnergy(void) const
{
	return (this->_energy);
}
unsigned int ClapTrap::getDamage(void) const
{
	return (this->_damage);
}
void ClapTrap::setName(const std::string name)
{
	this->_name = name;
}
void ClapTrap::setHit(const unsigned int nbr)
{
	this->_hit = nbr;
}
void ClapTrap::setEnergy(const unsigned int nbr)
{
	this->_energy = nbr;
}
void ClapTrap::setDamage(const unsigned int nbr)
{
	this->_damage = nbr;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hit == 0)
		std::cout << std::endl
					<< "ClapTrap " << this->_name << " can't attack... he's dead !" << std::endl;
	else if (this->_energy == 0)
		std::cout << "ClapTrap " << this->_name << " have no more energy point ... he can't attack" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->_damage;
		std::cout << " points of damage!" << std::endl;
		this->_energy--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit == 0)
		std::cout << std::endl
					<< "... but ClapTrap R3PO " << this->_name << " can't take damages... he's dead !" << std::endl;
	else
	{
		std::cout << "ClapTrap  " << this->_name;
		std::cout << " took " << amount;
		std::cout << " points of damage!" << std::endl;
		if (amount > this->_hit)
			this->_hit = 0;
		else
			this->_hit -= amount;
		if (this->_hit == 0)
			std::cout << "ClapTrap  " << this->_name << " is dead !" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit == 0)
		std::cout << std::endl
					<< "ClapTrap " << this->_name << " can't fix himself... he's dead !" << std::endl;
	else if (this->_energy == 0)
		std::cout << "ClapTrap  " << this->_name << " have no more energy points ... he can't fix himself" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " recovered " << amount;
		std::cout << " points of hit !" << std::endl;
		// le nombre le plus élevé possible qu'un système 32 bits peut stocker en mémoire.
		if (4294967295 - amount < this->_hit)
			this->_hit = 4294967295;
		else
			this->_hit += amount;
		this->_energy--;
	}
}
