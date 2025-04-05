#include "WrongCat.hpp"

WrongCat::WrongCat(){
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original){
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &original){
	std::cout << "WrongCat overload assignement operator called" << std::endl;
	if (this != &original)
	{
		type = original.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/*void	Cat::makeSound() const {
	std::cout << "MIAU MIAU" << std::endl;
}*/
