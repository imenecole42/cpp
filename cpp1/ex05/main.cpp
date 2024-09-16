
#include "Harl.hpp"
#include <iostream>

int main( int argc, const char **argv )
{
	Harl	harl;

	if ( argc == 1 )
		std::cout << "please specify your comment" << std::endl;
	for ( int i(1); i < argc; i++ )
		harl.complain( argv[i] );
	return 0;
}
