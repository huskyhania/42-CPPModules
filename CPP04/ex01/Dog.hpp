#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &original);
		Dog &operator = (const Dog &original);
		virtual ~Dog();
		void	makeSound() const override;
		void	think(int index, const std::string& idea);
		void	thinkOutLoud(int index) const;
};

#endif
