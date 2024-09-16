#include "zombie.hpp"
#include<stdio.h>
#include <climits>
void write_err(int choix)
{
	if(choix==1)
    	std::cerr<<"Invalid input: you must first enter the name of the zombie horde and then, the number of zombie in the hordes."<<std::endl;
	else 
		std::cerr<<"Invalid input: the number of zombie in the hordes must be between 0 and 2147483647."<<std::endl;
	exit(EXIT_FAILURE);


}
int	check_digit(char *str)
{
	int				i(0);

	while (str[i] =='0')
		i++;
	for (int i(0); str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return (0);
	}
	if (i > 12 || std::atoi(str) > INT_MAX)
		return (0);
	return (1);
}
int	main(int argc, char **argv)
{
	int			nb;
	string		name;
	zombie		*zombie;

	if (argc != 3)
		write_err(1);
	if (!check_digit(argv[2]))
		write_err(2);
	name = argv[1];
	nb = std::atoi(argv[2]);
	if (nb)
		zombie = zombieHorde(nb, name);
	for (int i(0); i < nb && zombie; i++)
		zombie[i].annonce();
	delete [] zombie;
	return (EXIT_SUCCESS);
}
