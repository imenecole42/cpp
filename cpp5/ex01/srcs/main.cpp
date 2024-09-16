#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
 try
 {
    Form form1("Default", 1, 1);
    Bureaucrat bureaucrat1("Bureaucrat1", 1);
    std::cout << bureaucrat1 << std::endl;
    std::cout << form1 << std::endl;
   bureaucrat1.signForm(form1);
 }
 catch(const std::exception& e)
 {
    std::cerr << e.what() << std::endl;
 }
 std::cout << "---------------------" << std::endl;
 try
 {
        Form form2("Form2", 150, 150);
        Bureaucrat bureaucrat2("Bureaucrat2", 1);
        std::cout << bureaucrat2 << std::endl;
        std::cout << form2 << std::endl;
        bureaucrat2.signForm(form2);
 }
 catch(const std::exception& e)
 {
    std::cerr << e.what() << std::endl;
 }
   std::cout << "---------------------" << std::endl;
 try
 {
    Form form3("Form3", 1, 1);
    Bureaucrat bureaucrat3("Bureaucrat3", 150);
    std::cout << bureaucrat3 << std::endl;
    std::cout << form3 << std::endl;
    bureaucrat3.signForm(form3);
 }
 catch(const std::exception& e)
 {
    std::cerr << e.what() << std::endl;
 }
   std::cout << "---------------------" << std::endl;
   try
    {
        Bureaucrat B1("B1", 155);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat B2("B2", 0);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
      std::cout << "---------------------" << std::endl;
    Form form_1("Form 1", 5, 10);
    //false
    Bureaucrat B4("B4", 150);
    B4.signForm(form_1);
    std::cout << std::endl;
    Bureaucrat B3("B3", 1);
    //true
    B3.signForm(form_1);
    std::cout << std::endl;
    //surcharge Bureaucrat
    std::cout<<B3;
    //copy bureaucrat et =
    Bureaucrat B5(B3);
    std::cout<<B5;
    Bureaucrat B6;
    B6 = B3;
    std::cout<<B6;
    //copy form

    //surcharge << form
    std::cout<<form_1;

    // copy et = form 
    Form form_2(form_1);
    std::cout<<form_2;

    Form form_3;
    form_3 = form_1;
    std::cout<<form_3;
}

