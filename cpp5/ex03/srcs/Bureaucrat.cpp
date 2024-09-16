#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Bureaucrat::Bureaucrat():_name("Default"),_grade(150)
{
	std::cout<<"Bureaucrat:"<<_name<<"created name"<<std::endl;
	
}


Bureaucrat::Bureaucrat(const std::string name,int grade):_name(name),_grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if(grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat & other):_name(other._name),_grade(other._grade)
{

}
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

const std::string	&Bureaucrat::getName() const
{
	return(this->_name);
}

int	Bureaucrat::getGrade() const
{
	return(this->_grade);
}

std:: ostream & operator << ( std:: ostream & out, const Bureaucrat & obj ) 
{ 
	out << obj.getName() << ", bureaucrat grade : " << obj.getGrade()<<std::endl; 
	return out ; 
}


void				Bureaucrat::incrGrade(int nb)
{
	_grade -=nb;
	if (_grade < 1)
		throw GradeTooHighException();
}

void				Bureaucrat::decrGrade(int nb)
{
	_grade += nb;
	if (_grade > 150 )
		throw GradeTooLowException();
}
void Bureaucrat::signAForm(AForm &form) const
{
   try{
        form.beSigned(*this);
        std::cout << this->_name << " signs " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
   }
}
void Bureaucrat::executeForm(const AForm  &form)
{
    try{
        form.execute(*this);
        std::cout << this->_name << " executes " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
   }
}
Bureaucrat::~Bureaucrat() 
{
	std::cout << "Default destructor called" << std::endl;
}