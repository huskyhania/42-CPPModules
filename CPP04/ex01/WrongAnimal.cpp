#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("general") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type){
	std::cout << "WrongAnimal parameter construcor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &original) : type(original.type){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &original){
	std::cout << "WrongAnimal overload assignment operator called" << std::endl;
	if (this != &original)
	{
		type = original.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "*generic wrong animal sound*" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}
