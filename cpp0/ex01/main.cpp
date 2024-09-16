#include "PhoneBook.hpp"

int main()
{
	std::string input;
	PhoneBook phonebook;

	std :: cout << std :: endl << "    Hello, dear master," << std :: endl;
	std :: cout << std :: endl << "    you can now choose what you want to do : " << std :: endl << std :: endl;
	std :: cout << "        - add a new contact (ADD)." << std :: endl;
	std :: cout << "        - display contacts registered (SEARCH)." << std :: endl;
	std :: cout << "        - exit (EXIT)." << std :: endl << std :: endl;
	while (1)
	{
		std ::cout << "    Enter your choice : ";
		std ::getline(std ::cin, input);
		if (std::cin.eof())
			exit (EXIT_FAILURE);
		if (input == "ADD")
		{
			Contact contact;
			if (phonebook.push_contact(contact))
				return (1);
		}
		else if (input == "SEARCH")
		{
			if (!phonebook.printlist(phonebook.contact_nbr()))
			{
				std::cout << "      Enter the index of the contact :" ;
				while (1)
				{
					std ::getline(std ::cin, input);
					if (std::cin.eof())
							exit (EXIT_FAILURE);
					if (std::atoi(input.c_str()) <= 8 && std::atoi(input.c_str()) >= 1)
					{
						phonebook.printcontact(std::atoi(input.c_str()) - 1);
						break ;
					}
					else
						std::cout << "Wrong Index Value (range : 1 - 8)" << std::endl;
				}
			}
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid input. Try again." << std::endl;
	}
	return (0);
}