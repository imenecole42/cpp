#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
void replace_file(std::ifstream &read,std::ofstream &write,char **argv,const std::string name_fd)
{
	std::string s1=argv[2];
	std::string s2=argv[3];
	std::string	ligne;
	std::size_t found;
	std::getline(read,ligne);
	if ( read.eof() && ligne == "")
	{
		std ::cout << "ligne empty." << std::endl;
		read.close();
		exit( EXIT_FAILURE );
	}
	// vérifier si le flux a généré une mauvaise erreur.
	if ( read.bad())
	{
		std ::cout << "ERROR:erreur read in file." << std::endl;
		read.close();
		exit( EXIT_FAILURE );
	}
	write.open( name_fd.c_str(), std::ofstream::out | std::ofstream::trunc );
	//verifier si on peux ouvrir fd
	if(!write.is_open())
	{
		std ::cout << "ERROR:open file." << std::endl;
		read.close();
		exit( EXIT_FAILURE );
	}
	do
	{
		found=ligne.find(s1);
		while ( found != std::string::npos && s1 != " " )
		{
			ligne.erase(found,s1.size());
			ligne.insert( found, s2 );
			found=ligne.find(s1);
		}
		write<<ligne<<std::endl;
		
	} while (std::getline( read,ligne ));
	write.close();
}
int main(int argc ,char **argv)
{	
	std::ifstream	read( argv[1], std::ifstream::in );	
	std::ofstream write;
	std::string	name_fd;
	if(argc != 4)
	{
		std::cout<<"ERROR:number argumen"<<std::endl;
		exit(EXIT_FAILURE);
	}
	if(read.is_open())
	{
		name_fd = argv[1];
		name_fd += ".replace";
		replace_file( read, write, argv, name_fd );
		write.close();
	}
	else
	{
   		std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
	}

}