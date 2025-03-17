#include <iostream>
#include <cctype>

class PhoneBook
{
public:
	Contact Contacts[8];
	int	count;
	int	oldest;
};
class Contact
{
public:
	FirstName;
	LastName;
	Nickname;
	PhoneNumber;
private:
	DarkestSecret;
}

int main(void)
{
	PhoneBook	pk = PhoneBook();
	std::string	command;
	
	while (1)
	{
		std::sout << "Enter a command ADD, SEARCH or EXIT: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			PhoneBook.addContact();
		else if (command == "SEARCH")
			PhoneBook.searchContact();
		else if (command == "EXIT")
			break ;
		else
			std:sout << "Enter a valid command";
	}
	return (0);
}

