/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:01:02 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/20 10:01:09 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iomanip>
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
PhoneBook::~PhoneBook(){}

void	PhoneBook::addContact(void)
{
	int flag = 0;
	std::string first, last, nick, number, secret;
	std::string prompts[] = {
		"Type first name: ",
		"Type last name: ",
		"Type nickname: ",
		"Type phone number: ",
		"Type darkest secret: "
	};
	std::string* inputs[] = { &first, &last, &nick, &number, &secret };
	for (int i = 0; i < 5; ++i) {
		int attempts = 0;
        while (attempts < 3)
		{
            *inputs[i] = getInput(prompts[i], flag);
            if (flag) return;
			if (!inputs[i]->empty()) break;
			attempts++;
			std::cout << "Input cannot be empty. Attempts left: " << (3 - attempts) << std::endl;
        }
		if (attempts == 3){
			std::cout << "Back to the main menu\n";
			return;
		}
    }
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

std::string formatText(std::string text)
{
    if (text.length() > 10)
        return text.substr(0, 9) + ".";
    return text;
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
	std::string searched = getInput("Which index do you want to see?", flag);
	if (flag) return ;
	if (searched.length() == 1 && std::isdigit(searched[0]))
	{
		int index = searched[0] - '0';
		if (index < 1 || index > count)
			std::cout << "Number out of range\n";
		else
			Contacts[index - 1].printFull();
	}
	else
		std::cout << "Invalid search attempt\n";
}
