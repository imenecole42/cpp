/*try{ ...}  ("essaie", en français) signale une portion de code où une erreur peut survenir ;

throw  ("lance", en français) signale l'erreur en lançant un objet ;

catch(...){...}  ("attrape", en français) introduit la portion de code qui récupère l'objet et gère l'erreur.*/
#include "Bureaucrat.hpp"

#include <iostream>

int main() {
	std::cout << "----------------------------------------" << std::endl;
	
	try
	{
		Bureaucrat hooman("Hooman", 100);
		std::cout << hooman << std::endl;
	}

	catch (const std::exception &e) {
		std::cout << "Exception caught : " << e.what() << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	try {
		Bureaucrat wooman("Wooman", 200);
		std::cout << wooman << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception caught : " << e.what() << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	try {
		Bureaucrat dooman("Dooman", 140);
		std::cout << dooman << std::endl;
		dooman.decrGrade(11);
	} catch (const std::exception &e) {
		std::cout << "Exception caught : " << e.what() << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	try {
		Bureaucrat fooman("Fooman", 5);
		std::cout << fooman << std::endl;
		fooman.incrGrade(5);
	} catch (const std::exception &e) {
		std::cout << "Exception caught : " << e.what() << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	try {
		Bureaucrat troudbal("Troudbal", 149);
		std::cout << troudbal << std::endl;
		Bureaucrat trouduc("Trouduc", 14);
		std::cout << trouduc << std::endl;
		troudbal = trouduc;
		troudbal.incrGrade(4);
		std::cout << troudbal << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception caught : " << e.what() << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	return (0);
}
