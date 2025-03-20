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

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "Phonebook.hpp"

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

Contact::~Contact(){}
