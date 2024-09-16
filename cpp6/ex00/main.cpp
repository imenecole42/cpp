#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		try
		{
			std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
			ScalarConverter::convert(av[1]);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Usage: ./convert <value>" << std::endl;
	return (0);
}