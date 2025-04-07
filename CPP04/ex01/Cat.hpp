#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(const Cat &original);
		Cat &operator = (const Cat &original);
		virtual ~Cat();
		void	makeSound() const override;
		void	think(int index, const std::string& idea);
		void	thinkOutLoud(int index) const;
};

#endif
