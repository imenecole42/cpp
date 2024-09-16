#include"Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
Base	*generate( void )
{
	srand(time(NULL));
	int	nb = rand() % 3;
	switch ( nb )
	{
		case 0:
			return ( new A );
		case 1:
			return ( new B );
		default:
			return ( new C );
	}
	return ( NULL );
}

void	identify( Base* p )
{
	if(!p)
		std::cout<<"NULL"<<std::endl;
	if ( dynamic_cast<A *>(p) )
		std::cout << "Base:Class A" << std::endl;
	else if ( dynamic_cast<B *>(p) )
		std::cout << "Base:Class B" << std::endl;
	else if ( dynamic_cast<C *>(p) )
		std::cout << "Base:Class C" << std::endl;
	else
		std::cout<<"Convertion Failed"<< std::endl;
}
void identify(Base& p) {
    identify(&p);
}
int main() {

    Base* obj = generate();
    identify(obj);
    
    delete obj;

    return 0;
}
