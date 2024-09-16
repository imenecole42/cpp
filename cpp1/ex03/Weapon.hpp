#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Weapon
{
private:
	std ::string _type ;
public:
	Weapon(std :: string type);
	~Weapon(void);
	const std::string &getType(void)const;
	void setType(std::string type);
};


#endif
