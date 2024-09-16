#ifndef INTERN_HPP 
#define INTERN_HPP
#include "AForm.hpp"
#include <iostream>
#include <string>
class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
		AForm *makeForm(std::string name, std::string target);
        class FormNotFoundException : public std::exception
        {
        	public:
            	virtual const char* what() const throw()
            	{
               	 	return ("Form not found!\n");
            	}
        };
};
#endif