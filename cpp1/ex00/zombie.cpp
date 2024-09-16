#include "zombie.hpp"

zombie::zombie(string name)
{
    this->_name = name;
}

zombie::~zombie()
{
    cout << this->_name << ": zombie destroyed" << endl;
}

void	zombie::annonce( void )const
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}

zombie*	newzombie( std::string name )
{
	zombie	*zombie1;

	zombie1 = new zombie(name);
	return (zombie1);
}

void	randomChump( string name )
{
	zombie zombie1(name);

	zombie1.annonce();
}