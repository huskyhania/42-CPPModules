/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:00:35 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/20 10:00:44 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

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
		{
			pk.addContact();
			if (std::cin.eof())
			{
				std::cout << "EOF detected. Exiting...\n";
				break ;
			}
		}
		else if (command == "SEARCH")
		{
			if (pk.count == 0)
				std::cout << "Phonebook is empty\n";
			else
			{
				pk.searchContact();
				if (std::cin.eof())
				{
					std::cout << "EOF detected. Exiting...\n";
					break ;
				}
			}
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
