#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm",145,137)
{
	this->_target ="default";
	std::cout<<"ShrubberyCreationForm Default constructeur called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target ): AForm("ShrubberyCreationForm",145,137),_target(target)
{
	std::cout<<"ShrubberyCreationForm Default constructeur called"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other ): AForm(other.getName(),other.getsignedGrade(),other.getexecuteGrade()),_target(other._target)
{
	std::cout<<"ShrubberyCreationForm Default copy called"<<std::endl;
}
ShrubberyCreationForm & ShrubberyCreationForm :: operator=(const ShrubberyCreationForm &other )
{
	if(this != &other)
		this->_target= other._target;
	return(*this);
}
ShrubberyCreationForm ::~ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm  Destructer called"<<std::endl;
}
std::string ShrubberyCreationForm  ::getTarget() const
{
	return(this->_target);
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if(this->getsigned()==0)
        throw AForm::FormNotSigned(); 
    else if(executor.getGrade() > this->getexecuteGrade())
        throw AForm::GradeTooLowException();
    else
    {
        std::string filename = this->_target + "_shrubbery";
        std::ofstream outfile(filename.c_str());
		if (outfile) 
		{
			outfile << "    *" << std::endl;
			outfile << "   ***" << std::endl;
			outfile << "  *****" << std::endl;
			outfile << " *******" << std::endl;
			outfile << "****|****" << std::endl;
			outfile.close();
		}
		else 
		{
			std::cout << "Failed to create the file : " << filename << std::endl;
		}
	}
}