#ifndef __FORM_HPP__
#define __FORM_HPP__

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name,int sGrade,int eGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		class GradeTooHighException  : public std::exception 
		{
			public:
				const char *what() const throw()
				{
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception 
		{
			public:
				const char *what() const throw()
				{
					return "Grade is too low";
				}
		};

		const std::string &getName()const;
		bool getsigned()const;
		int getsignedGrade()const;
		int getexecuteGrade()const;
		void beSigned(const Bureaucrat & Be);
		
	private:

		const std::string _name;
		bool _signed;
		const int _signedgrade;
		const int _execgrade;

};
std:: ostream & operator << ( std:: ostream & out, const Form & obj ) ;
#endif
