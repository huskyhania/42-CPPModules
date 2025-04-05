#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public:
		WrongCat();
		WrongCat(const WrongCat &original);
		WrongCat &operator = (const WrongCat &original);
		~WrongCat();
		//void makeSound() const override;
};

#endif
