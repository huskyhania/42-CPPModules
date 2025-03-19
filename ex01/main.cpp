#include "Phonebook.hpp"
#include <iostream>
#include <string>
#include "Contact.hpp"

int main(void)
{
	PhoneBook	pk = PhoneBook();
	std::string	command;
	
	while (1)
	{
		std::cout << "Enter a command ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEOF detected. Exiting...\n";
			break;
		}
		if (command == "ADD")
			pk.addContact();
		else if (command == "SEARCH")
		{
			if (pk.count == 0)
				std::cout << "Phonebook is empty\n";
			else
				pk.searchContact();
		}
		else if (command == "EXIT")
		{
			std::cout << "Closing phonebook..." << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
