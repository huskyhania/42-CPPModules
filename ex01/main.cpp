#include "Phonebook.hpp"
#include <iostream>
#include <string>
#include "Contact.hpp"

/*std:string getInput()
{
	std::string	userInput;
	std::cout << "Give me input: ";
	std::getline(std::cin, userInput);
	std::cout << userInput << std::endl; 
}*/

int main(void)
{
	PhoneBook	pk = PhoneBook();
	std::string	command;
	
	while (1)
	{
		std::cout << "Enter a command ADD, SEARCH or EXIT: ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			std::cout << command << std::endl;
			pk.addContact();
		}
		else if (command == "SEARCH")
		{
			std::cout << command << std::endl;
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
