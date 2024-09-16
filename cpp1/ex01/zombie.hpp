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
		zombie( void );
		~zombie(void);
    	void annonce( void )const;
		void setname(string name);
	private:
    	string _name;
	
};
zombie* zombieHorde(int N, std::string name);
#endif