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
