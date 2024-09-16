

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <cstdlib>
#include <iostream>

int main( void )
{
	FragTrap	x( "lina" );
	FragTrap y( FragTrap( "ismael" ) );
	x = y;

	std::cout << std::endl;
	std::cout << "Name : " << x.getName() << std::endl;
	std::cout << "Hit points : " << x.getHit() << std::endl;
	std::cout << "Energy points : " << x.getEnergy() << std::endl;
	std::cout << "Damage points : " << x.getDamage() << std::endl;
	std::cout << std::endl;
	x.attack( "lina" );
	x.takeDamage( 0 );
	x.beRepaired( 0 );
	std::cout << std::endl;
	x.highFivesGuys();
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}
