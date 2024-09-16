#include "../headers/Intern.hpp"
#include "../headers/AForm.hpp"
#include"../headers/RobotomyRequestForm.hpp"
#include"../headers/PresidentialPardonForm.hpp"
#include"../headers/ShrubberyCreationForm.hpp"


Intern::Intern()
{
	std::cout<<"Intern:Default constructeur called"<<std::endl;
}
Intern::Intern(const Intern &other)
{
	*this=other;
	std::cout<<"Intern:copy"<<std::endl;
}
Intern &Intern ::operator=(const Intern &other)
{
	if(this != &other)
		*this=other;
	return(*this);
}
Intern::~Intern()
{
	std::cout<<"Intern:destructeur  called";
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    AForm *form;
    int i;
    std::string form_type[3] = {"RobotomyRequestForm", "PresidentialPardonForm", "ShrubberyCreationForm"};
    for(i = 0; i < 3; i++)
    {
        if (name == form_type[i])
            break;
    }
    switch (i)
    {
    case 0:
        form = new RobotomyRequestForm(target);
        break;
    case 1:
        form = new PresidentialPardonForm(target);
        break;
    case 2:
        form = new ShrubberyCreationForm(target);
        break;
    default:
        throw Intern::FormNotFoundException();
        break;
    }
    std::cout << "Intern creates " << form->getName() << " ,the target is " << form->getTarget() << std::endl;
    return (form);
}