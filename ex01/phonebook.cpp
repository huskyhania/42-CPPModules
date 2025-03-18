#include <iostream>
#include <cctype>
#include <string>
#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iomanip>

std::string getInput(std::string prompt)
{
	std::string	userInput;
	std::cout << prompt << std::endl;
	std::getline(std::cin, userInput);
	std::cout << userInput << std::endl;
	return (userInput); 
}

PhoneBook::PhoneBook()
{
	count = 0;
	oldest = 0;
}

void	PhoneBook::addContact(void)
{
	std::string first = getInput("Type first name: ");
	std::string last = getInput("Type last name: ");
	std::string nick = getInput("Type nickname: ");
	std::string number = getInput("Type phone number: ");
	std::string secret = getInput("Type darkest secret: ");
	if (first.empty() || last.empty() || nick.empty() || number.empty() || secret.empty())
	{
		std::cout << "Fill all the fields" << std::endl;
		return ;
	}
	else 
	{
		std::cout << "Contact added" << std::endl;
		//test
		std::cout << first << last << nick << number << std::endl;
		Contact Contact(first, last, nick, number, secret);
		if (count < 8)
		{
			Contacts[count] = Contact;
			count++;
		}
		else
		{
			Contacts[oldest] = Contact;
			oldest = (oldest + 1) % 8;
		}
	}
}

std::string formatText(std::string text)
{
    if (text.length() > 10)
        return text.substr(0, 9) + ".";
    return text;
}

void	PhoneBook::searchContact(void)
{
	if (count == 0)
	{
		std::cout << "Phonebook is empty\n";
		return ;
	}
	std::cout << "Summary: \n";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;


	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|" 
		<< std::setw(10) << formatText(Contacts[i].getFirstName()) << "|"
		<< std::setw(10) << formatText(Contacts[i].getLastName()) << "|"
		<< std::setw(10) << formatText(Contacts[i].getNickname()) << std::endl;		
	}
	std::string searched =  getInput("Which index do you want to see?\n";)
	if (searched.length != 1 || searched.at(0) >= count)
	{
		std::cout << "Invalid index\n";
		return ;
	}
	else
		Contacts[searched - 1].print_full();

}
