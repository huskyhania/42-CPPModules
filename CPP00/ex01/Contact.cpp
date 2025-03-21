/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:59:45 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/20 09:59:51 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	firstName = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	darkestSecret = "";
}

Contact::Contact(std::string name, std::string surname, std::string nick, std::string number, std::string secret)
{
	firstName = name;
	lastName = surname;
	nickName = nick;
	phoneNumber = number;
	darkestSecret = secret;
}

std::string	Contact::getFirstName() { return (firstName); }

std::string Contact::getLastName() { return (lastName); }

std::string Contact::getNickname() { return (nickName); }

std::string Contact::getNumber() { return (phoneNumber); }

std::string Contact::getSecret() { return (darkestSecret); }

void	Contact::printFull()
{
	std::cout << "First name: " << getFirstName() << std::endl;
	std::cout << "Last name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Phone  Number: " << getNumber() << std::endl;
	std::cout << "Darkest Secret: " << getSecret() << std::endl;
}

Contact::~Contact(){}
