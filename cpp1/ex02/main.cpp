#include <string>
#include <iostream>
#include<unistd.h>
int main(void)
{
	std::string str="HI THIS IS BRAIN";
	std::string *stringPTR=&str;
	std::string &stringREF=str;

	std::cout<<std::endl;
	std::cout<< "	address of the string in memory = "<<&str<<std::endl;
	std::cout<< "	address stored in stringPTR = "<<stringPTR<<std::endl;
	std::cout<< "	address stored in stringREF = "<<&stringREF<<std::endl;
	std::cout<<std::endl;
	std::cout<< "	value string str = "<<str<<std::endl;
	std::cout<< "	value  stringPTR = "<<*stringPTR<<std::endl;
	std::cout<< "	value string stringREF = "<<stringREF<<std::endl;
	std::cout<<std::endl;
	return(0);
}