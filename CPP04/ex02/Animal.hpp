#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &original);
		virtual ~Animal();
		Animal &operator = (const Animal &original);
		virtual void makeSound() const = 0; //this makes a function pure virtual, meaning the class is now abstract
		virtual std::string getType() const;
};

#endif
