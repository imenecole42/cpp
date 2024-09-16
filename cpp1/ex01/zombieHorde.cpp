#include "zombie.hpp"
#include <sstream>
zombie* zombieHorde(int N, string name)
{
	zombie *horde = new zombie[N];
	std::string new_name;
    int i=0;
	while (i < N)
	{
		std::ostringstream oss; //Un flux permettant d'écrire dans une chaîne  
		oss << name << (i + 1);
		new_name = oss.str();
		horde[i].setname(new_name);
		new_name.erase();
        i++;
	}
	return (&(horde[0]));
}

