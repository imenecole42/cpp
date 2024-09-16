
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index=0;
	nbr_contact=0;
}

PhoneBook::~PhoneBook()
{}

int	PhoneBook::ref_index() const
{
	return (index);
}

int	PhoneBook::contact_nbr() const
{
	return (nbr_contact);
}

int	PhoneBook::push_contact(Contact contact)
{
	if (index + 1 > 8)
		index = 0;
	if (contact.new_contact(&_contact[index]))
		return (1);
	index++;
	if (nbr_contact < 8)
		nbr_contact++;
	return (0);
}

void PhoneBook::printcontact(int i) const
{
	_contact[i].crush_contact();
}

int PhoneBook::printlist(int contact_nbr) const
{
	if (contact_nbr == 0)
	{
		std::cout << std::right << "Empty phone book at the moment" << std::endl;
		return (1);
	}
	std::cout << "#    Index#First Name# Last Name#  Nickname#" << std::endl;
	for (int i = 0; i < contact_nbr; i++)
	{
		_contact[i].table_contact(i);
	}
	std::cout << "############################################" << std::endl;
	return (0);
}