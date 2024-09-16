#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	ClapTrap x("lina");
	ClapTrap y("Ismael");
	y = ClapTrap("Imen");

	std::cout << std::endl;
	std::cout << "x -> Name : " << x.getName() << std::endl;
	std::cout << "x -> Hit points : " << x.getHit() << std::endl;
	std::cout << "x -> Energy points : " << x.getEnergy() << std::endl;
	std::cout << "x -> Damage points : " << x.getDamage() << std::endl;
	std::cout << std::endl;

	y.setDamage(5);

	std::cout << std::endl;
	for (int i(0); i < 8; i++)
	{
		y.attack("lina");
		x.takeDamage(y.getDamage());
		x.beRepaired(5);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	y.attack("lina");
	x.takeDamage(y.getDamage());
	x.beRepaired(0);
	x.beRepaired(0);
	x.beRepaired(0);
	std::cout << std::endl;
	y.attack("lina");
	x.takeDamage(y.getDamage());
	std::cout << std::endl;
	y.attack("lina");
	x.beRepaired(0);
	x.attack("imen");
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}