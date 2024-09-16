#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm",72,45)
{
	this->_target="Default";
	std::cout<<"RobotomyRequestForm:Default constructeur called"<<std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm",72,45),_target(target)
{
	std::cout<<"RobotomyRequestForm:constructeur called"<<std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other.getName(),other.getsignedGrade(),other.getexecuteGrade()),_target(other._target)
{
	std::cout<<"RobotomyRequestForm:constructeur copy"<<std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if(this != &other)
		this->_target=other._target;
	return(*this);
}	
RobotomyRequestForm::~RobotomyRequestForm()
{
		std::cout<<"RobotomyRequestForm:Destructeur missed called"<<std::endl;
}
std::string RobotomyRequestForm ::getTarget ()const
{
	return(this->_target);
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    int robot;
    srand(time(NULL));//robot 
    robot = rand() % 2;//nbr alleatoire soit 0 soit 1
    if(this->getsigned()==0)
        throw AForm::FormNotSigned(); 
    else if(executor.getGrade() > this->getexecuteGrade())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << "Drr......." << std::endl;
        if(robot == 0)
            std::cout << this->_target << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->_target << " has not been robotomized successfully" << std::endl;
    }
}