/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:01:18 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/20 10:01:22 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact Contacts[8];
		int	oldest;
	public:
		int count;
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact();
};

#endif
