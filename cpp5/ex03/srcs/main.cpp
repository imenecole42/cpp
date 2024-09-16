#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main( void )
{
    try
    {
        Intern  someRandomIntern;
        AForm*   rrf;

        rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        std::cout << *rrf << std::endl;
       delete rrf;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << "---------------------" << std::endl;

    try 
    {
        Intern imraoui;
        AForm*  FCR;
        
        FCR = imraoui.makeForm("ShrubberyCreationForm", "home");
        std::cout << *FCR << std::endl;
        delete FCR;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << "---------------------" << std::endl;
    try
    {
        Intern bestIntern;
        AForm*  UB40;
        
        UB40 = bestIntern.makeForm("PresidentialPardonForm", "white house");
        std::cout << *UB40 << std::endl;
       delete UB40;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
    std::cout << "---------------------" << std::endl;
    try
    {
        Intern badIntern;
        AForm*  badForm;

        badForm = badIntern.makeForm("bad form", "bad target");
        std::cout << *badForm << std::endl;
        delete badForm;
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}
