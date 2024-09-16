
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

ScavTrap::ScavTrap(void): ClapTrap()
{
	this->_damage = 20;
	this->_hit = 100;
	this->_energy = 50;
	cout << "ScavTrap  " << this->_name << " Default Constructor" << endl;
}

ScavTrap::ScavTrap(const std::string name)
	: ClapTrap(name)
{
	this->_damage = 20;
	this->_hit = 100;
	this->_energy = 50;
	cout << "ScavTrap  " << this->_name << " Constructor" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other.getName())
{
	*this = other;
	cout << "SlavTrap  " << this->_name << " Copy Constructor" << endl;
}

ScavTrap::~ScavTrap(void)
{
	cout << "ScavTrap  " << this->_name << " Destructor" << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

void ScavTrap::attack(const std::string &target)
{
	if (this->_hit == 0)
		cout << endl
				<< "The wonderfull ScavTrap  " << this->_name << " can't attack... he's dead !" << endl;
	else if (this->_energy == 0)
		cout << "The wonderfull ScavTrap  " << this->_name << " have no more energy point ... he can't attack" << endl;
	else
	{
		cout << "The wonderfull ScavTrap  " << this->_name;
		cout << " attacks " << target;
		cout << ", causing " << this->_damage;
		cout << " points of damage!" << endl;
		this->_energy--;
	}
}

void ScavTrap::guardGate(void)
{
	if (this->_hit == 0)
		cout << endl
				<< "ScavTrap  " << this->_name << " can't say something... he's dead !" << endl;
	else if (this->_energy == 0)
		cout << "ScavTrap  " << this->_name << " have no more energy point ... he can't say something" << endl;
	else
	{
		cout << "ScavTrap  " << this->_name << " said : \"GATEKEEPER MODE !!!!\"" << endl;
		this->_energy--;
	}
}
