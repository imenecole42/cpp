
#include "Harl.hpp"
#include <iostream>

int main( int argc, char **argv )
{
	Harl	Harl;

	switch ( argc )
	{
		case 1:
			std::cout << "please specify your comment" << std::endl;
			break;
		case 2:
			Harl.complain( argv[1] );
			break;
		default:
			std::cout << "Too many argument" << std::endl;
	}
	return 0;
}
