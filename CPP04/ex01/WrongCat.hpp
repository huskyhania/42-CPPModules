#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat: public WrongAnimal{
	private:
		Brain* brain;
	public:
		WrongCat();
		WrongCat(const WrongCat &original);
		WrongCat &operator = (const WrongCat &original);
		~WrongCat();
		//void makeSound() const override;
};

#endif
