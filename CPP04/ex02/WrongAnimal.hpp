#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>
#include <iostream>

class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &original);
		virtual ~WrongAnimal();
		WrongAnimal &operator = (const WrongAnimal &original);
		void makeSound() const;
		virtual std::string getType() const;
};

#endif
