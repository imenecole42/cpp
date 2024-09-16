#ifndef  PRESIDENTIALPARDONFORM_HPP__
#define  PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string traget);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();
		std::string getTarget() const;
    	virtual void execute(Bureaucrat const &executor) const;
	private :
		std::string _target;

};
#endif