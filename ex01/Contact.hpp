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
		std::string	getFirstName() { return (firstName); }
		std::string getLastName() { return (lastName); }
		std::string getNickname() { return (nickName); }
		std::string getNumber() { return (lastName); }
		void printFull();
};

#endif
