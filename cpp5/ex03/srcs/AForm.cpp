#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include<string.h>
AForm::AForm():_name("Default"),_signed(false),_signedgrade(150),_execgrade(150)
{
	std::cout << "AForm:dfault constructed called" <<std::endl;
}

AForm::AForm(std::string name,int sGrade,int eGrade):_name(name),_signed(0),_signedgrade(sGrade),_execgrade(eGrade)
{
	if((sGrade) < 1 || (eGrade) < 1 )
		throw GradeTooHighException();
	else if ((sGrade) > 150 || (eGrade) > 150 )
		throw GradeTooLowException();
}

AForm &AForm :: operator=(const AForm & other)
{
	if (this != &other)
		this->_signed = other._signed;	 
	return (*this);
}

AForm::AForm(const AForm &other):_name(other._name),_signed(other._signed),_signedgrade(other._signedgrade),_execgrade(other._execgrade)
{

}

const std::string &AForm:: getName()const
{
	return(this->_name);
}
int AForm:: getsignedGrade()const
{
	return(this->_signedgrade);
}
int AForm ::getexecuteGrade()const
{
	return(this->_execgrade);
}

bool AForm::getsigned()const
{
	return(this->_signed);
}
void AForm::beSigned(const Bureaucrat &Be)
{
	 if (Be.getGrade() > this->_signedgrade)
        throw AForm::GradeTooLowException();
    else
        this->_signed = true;
}
std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out << " AForm information: " << std::endl;
    out << " Name: " << obj.getName() << std::endl;
    out << " Signed: " << obj.getsigned() << std::endl;
    out << " Grade to sign: " << obj.getsignedGrade() << std::endl;
    out << " Grade to execute: " << obj.getexecuteGrade() << std::endl;
    return (out);
}
AForm::~AForm() 
{
	std::cout << "Default destructor called" << std::endl;
}
