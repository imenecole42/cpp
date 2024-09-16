
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	Animal *meta[10];

	for ( int i(0); i < 10; i++ )
	{
		if ( !(i % 2) )
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for ( int i(0); i < 10; i++ )
	{
		delete meta[i];
		std::cout << std::endl;
	}
	return 0;
}

