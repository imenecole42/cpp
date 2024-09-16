#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm",25,5)
{
	this->_target="Default";
	std::cout<<"PresidentialPardonForm Default constructeur called "<<std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm",25,5),_target(target)
{
	std::cout<<"PresidentialPardonForm : constructeur called "<<std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm(other.getName(),other.getsignedGrade(),other.getexecuteGrade()),_target(other._target)
{
	std::cout<<"PresidentialPardonForm : copy called"<<std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if(this != &other)
		this->_target=other._target;
	return(*this);
}

PresidentialPardonForm ::~PresidentialPardonForm()
{
	std::cout<<"PresidentialPardonForm Destructeur called "<<std::endl;
}
std::string PresidentialPardonForm:: getTarget()const
{
	return(this->_target);
}
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if(this->getsigned()==0)
        throw AForm::FormNotSigned(); 
    else if(executor.getGrade() > this->getexecuteGrade())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
    }
}