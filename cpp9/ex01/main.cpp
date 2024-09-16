#include "RPN.hpp"
int main(int argc,char **argv)
{
    if(argc != 2)
    {
        std::cerr<<"il faut declarer un argument"<<std::endl;
        return 0;
    }
    Rbn r;
    int rslt=0;
    rslt=r.ClaculRbn(argv[1]);
    if(rslt!=-999999)
        std::cout<<rslt<<std::endl;
    return 0;
}







