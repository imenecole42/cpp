#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string> 
#include <cstdlib>

using std::cout;
using std::string;
using std::endl;

class zombie
{
	public:

		zombie(string name);
		~zombie(void);
    	void annonce( void )const;

	private:
    	string _name;
	
};
zombie*	newzombie( string name );
void	randomChump( string name );

#endif
