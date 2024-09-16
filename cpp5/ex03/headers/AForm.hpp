#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(std::string name,int sGrade,int eGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		class GradeTooHighException  : public std::exception 
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is too low";
				}
		};
		class FormNotSigned : public std::exception
        {
        public:
            virtual const char* what() const throw()
            {
                return ("not signed, can't be executed!\n");
            }
        };
		
		const std::string &getName()const;
		bool getsigned()const;
		int getsignedGrade()const;
		int getexecuteGrade()const;
		virtual void execute(const Bureaucrat &executor) const = 0;
		virtual std::string getTarget() const = 0;
        virtual void  beSigned(const Bureaucrat &bureaucrat);
		
	private:

		const std::string _name;
		bool _signed;
		const int _signedgrade;
		const int _execgrade;

};
std:: ostream & operator << ( std:: ostream & out, const AForm & obj ) ;
#endif
