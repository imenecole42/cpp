#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <csignal>
#include <cstdlib>
#include <iomanip>

class Contact
{
	public:

	Contact();
	~Contact();
	
	void	check_cin(void);
	int		new_contact(Contact *contact);
	void	crush_contact() const;
	void	table_contact(int i) const;

	private:

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif