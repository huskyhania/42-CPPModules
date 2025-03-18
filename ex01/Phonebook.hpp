#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact Contacts[8];
		int	count;
		int	oldest;
	public:
		PhoneBook();
		void addContact();
		void searchContact();
};

#endif
