#ifndef ROBOTOMYREQUESTFORM__hpp
#define ROBOTOMYREQUESTFORM__hpp
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string.h>

class RobotomyRequestForm:public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		std::string getTarget() const;
    	virtual void execute(Bureaucrat const &executor) const;
	private:
		std::string _target;
};

#endif