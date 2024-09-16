
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string.h>
# include <fstream>
#include "AForm.hpp"


class ShrubberyCreationForm:public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		std::string getTarget() const;
    	virtual void execute(Bureaucrat const &executor) const;
	private:	
		std::string _target;
};
#endif