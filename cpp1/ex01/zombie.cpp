#include "zombie.hpp"

zombie::~zombie()
{
    cout << this->_name << ": Destructor use for delete" << endl;
}

void	zombie::annonce( void )const
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}

zombie::zombie( void )
{
	this->_name = "";
}

void	zombie::setname(string name)
{
	this->_name = name;
}



