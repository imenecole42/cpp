#include <iostream>
#include <string> 
#include <cstdlib>
#include "zombie.hpp"

void write_error(void)
{
    std::cerr << "error number argument name zombie and the memory 'stack' or 'heap'"<<endl;
    exit(EXIT_FAILURE);
}
int main(int argc,char **argv)
{
    std::string name;
    std::string type;
    zombie *zombie;
    if(argc==3)
    {
        name=argv[1];
        type=argv[2];
        if(type.compare("heap")==0)
        {
            zombie = newzombie(name);
		    zombie->annonce();
		    delete (zombie);
        }
        else if(type.compare("stack")==0)
        {
            randomChump(name);
        }
        else
            write_error();

    }
    else
        write_error();
}