#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
  protected:
	std::string _name;
	unsigned int _hit;
	unsigned int _energy;
	unsigned int _damage;

  public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &other);

	std::string getName(void) const;
	unsigned int getHit(void) const;
	unsigned int getEnergy(void) const;
	unsigned int getDamage(void) const;

	void setName(const std::string name);
	void setHit(const unsigned int nbr);
	void setEnergy(const unsigned int nbr);
	void setDamage(const unsigned int nbr);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
#endif
