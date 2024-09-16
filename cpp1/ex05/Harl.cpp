#include "Harl.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Harl::Harl( void )
{
	this->_fct[0] = &Harl::_debug;
	this->_fct[1] = &Harl::_info;
	this->_fct[2] = &Harl::_warning;
	this->_fct[3] = &Harl::_error;
	this->_fct[4] = &Harl::_msg;
}
Harl::~Harl( )
{}
void	Harl::_debug( void )
{
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << endl;
	cout << "I really do !" << endl;
}


void	Harl::_info( void )
{
	cout << "I cannot believe adding extra bacon costs more money" << endl;
	cout << "You didn’t put enough bacon in my burger ," << endl;
	cout << "If you did, I wouldn’t be asking for more !" << endl;
}

void	Harl::_warning( void )
{
	cout << "I think I deserve to have some extra bacon for free." << endl;
	cout << "I’ve been coming for years whereas you started working here since last month." << endl;
}


void	Harl::_error( void )
{
	cout << "This is unacceptable ! I want to speak to the manager now." << endl;
}

void	Harl::_msg( void )
{
	std::cerr << "No comment please choice : " << endl;
	std::cerr <<" *[DEBUG] " << endl;
	std::cerr <<" *[INFO]  " << endl;
	std::cerr <<" *[WARRNING]" << endl;
	std::cerr <<" *[ERROR]" << endl;
}

void	Harl::complain( std::string level )
{
	std::string		ptr[4] ;
	int i;
	ptr[0]="DEBUG";
	ptr[1]="INFO";
	ptr[2]="WARNING";
	ptr[3]="ERROR";

	for ( i = 0; i < 4 && ptr[i] != level; i++ )
		;
	(this->*_fct[i])();
}