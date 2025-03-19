#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include "Contact.hpp"
#include "Phonebook.hpp"

std::string getInput(std::string prompt, int &flag)
{
	std::string	userInput;
	std::cout << prompt << std::endl;
	if (!std::getline(std::cin, userInput))
	{
		std::cout << "\nEOF detected while filling data\n";
		flag = 1;
		return "";
	}
	return (userInput); 
}

PhoneBook::PhoneBook()
{
	count = 0;
	oldest = 0;
}

void	PhoneBook::addContact(void)
{
	int flag = 0;
	std::string first = getInput("Type first name: ", flag);
	if (flag) return ;
	std::string last = getInput("Type last name: ", flag);
	if (flag) return ;
	std::string nick = getInput("Type nickname: ", flag);
	if (flag) return ;
	std::string number = getInput("Type phone number: ", flag);
	if (flag) return ;
	std::string secret = getInput("Type darkest secret: ", flag);
	if (flag) return ;
	if (first.empty() || last.empty() || nick.empty() || number.empty() || secret.empty())
	{
		std::cout << "Fill all the fields" << std::endl;
		return ;
	}
	else 
	{
		std::cout << "Contact added" << std::endl;
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

void	Contact::printFull()
{
	std::cout << "First name: " << getFirstName() << std::endl;
	std::cout << "Last name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Phone  Number: " << getNumber() << std::endl;

}

void	PhoneBook::searchContact(void)
{
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
	int flag = 0;
	std::string searched =  getInput("Which index do you want to see?", flag);
	if (flag) return ;
	if (searched.length() == 1 && std::isdigit(searched[0]))
	{
		int index = searched[0] - '0';
		if (index < 1 || index > count)
			std::cout << "Number out of range\n";
		else
			Contacts[index - 1].printFull();
	}
}
