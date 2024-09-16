#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__


#include <iostream>

#include "Form.hpp"
#include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name,int grade);
		Bureaucrat(const Bureaucrat & other);
		Bureaucrat &operator=(const Bureaucrat & other);
		~Bureaucrat();

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

		void signForm(class Form & form) const;
		
		const std::string	&getName() const;
		const int			&getGrade() const;
		void				incrGrade(int nb);
		void				decrGrade(int nb);
	private:
		const std::string _name;
		int _grade ;

};

std:: ostream & operator << ( std:: ostream & out, const Bureaucrat & obj ) ;
#endif

