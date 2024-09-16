#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:

	PhoneBook();
	~PhoneBook();
	int		push_contact(Contact contact);
	int		printlist(int nbr_contact) const;
	void	printcontact(int index) const;
	int		ref_index() const;
	int		contact_nbr() const;

	private:

	int index;
	int	nbr_contact;
	Contact _contact[8];
};

#endif