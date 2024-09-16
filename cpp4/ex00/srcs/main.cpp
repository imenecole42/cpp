
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

//main exo
int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
delete i;
delete j;
return 0;
}
/*
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* l = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	std::cout << std::endl;

	std::cout << j->getType() << " : " << std::endl;
	j->makeSound();
	std::cout << std::endl;
	std::cout << i->getType() << " : " << std::endl;
	i->makeSound();
	std::cout << std::endl;
	std::cout << "Animal :" << std::endl;
	meta->makeSound();
	std::cout << std::endl;
	std::cout << "WrongAnimal : " << std::endl;
	l->makeSound();
	std::cout << std::endl;
	std::cout << k->getType() << " : " << std::endl;
	k->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	delete l;
	delete k;
	return 0;
}
*/