
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	ScavTrap x("lina");
	ScavTrap y(ScavTrap("ismael"));
	x = y;
	std::cout << std::endl;
	std::cout << "Name : " << x.getName() << std::endl;
	std::cout << "Hit points : " << x.getHit() << std::endl;
	std::cout << "Energy points : " << x.getEnergy() << std::endl;
	std::cout << "Damage points : " << x.getDamage() << std::endl;
	std::cout << std::endl;
	x.attack("lina");
	std::cout << std::endl;
	x.takeDamage(0);
	x.beRepaired(0);
	std::cout << std::endl;
	x.guardGate();
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
