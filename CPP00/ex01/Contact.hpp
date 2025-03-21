/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:00:16 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/20 10:00:22 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact();
		Contact(std::string name, std::string surname, std::string nick, std::string phoneNumber, std::string secret);
		std::string	getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getNumber();
		std::string getSecret();
		void printFull();
		~Contact();
};

#endif
