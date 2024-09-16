#include "Form.hpp"
#include "Bureaucrat.hpp"
#include<string.h>
Form::Form():_name("Default"),_signed(false),_signedgrade(150),_execgrade(150)
{
	std::cout << "Form:dfault constructed called" <<std::endl;
}

Form::Form(std::string name,int sGrade,int eGrade):_name(name),_signed(0),_signedgrade(sGrade),_execgrade(eGrade)
{
	if((sGrade) < 1 || (eGrade) < 1 )
		throw GradeTooHighException();
	else if ((sGrade) > 150 || (eGrade) > 150 )
		throw GradeTooLowException();
}

Form &Form :: operator=(const Form & other)
{
	if (this != &other)
		this->_signed = other._signed;	 
	return (*this);
}

Form::Form(const Form &other):_name(other._name),_signed(other._signed),_signedgrade(other._signedgrade),_execgrade(other._execgrade)
{

}

const std::string &Form:: getName()const
{
	return(this->_name);
}
int Form:: getsignedGrade()const
{
	return(this->_signedgrade);
}
int Form ::getexecuteGrade()const
{
	return(this->_execgrade);
}

bool Form::getsigned()const
{
	return(this->_signed);
}
void Form::beSigned(const Bureaucrat &Be)
{
	 if (Be.getGrade() > this->_signedgrade)
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
}
std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << " Form information: " << std::endl;
    out << " Name: " << obj.getName() << std::endl;
    out << " Signed: " << obj.getsigned() << std::endl;
    out << " Grade to sign: " << obj.getsignedGrade() << std::endl;
    out << " Grade to execute: " << obj.getexecuteGrade() << std::endl;
    return (out);
}
Form::~Form() 
{
	std::cout << "Default destructor called" << std::endl;
}
