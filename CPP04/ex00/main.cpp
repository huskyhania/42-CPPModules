#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <new>

int main(void)
{
	Animal One;
	Dog DogOne;
	Cat CatOne;

	One.makeSound();
	DogOne.makeSound();
	CatOne.makeSound();

	std::cout << std::endl << "--school main--" << std::endl << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << "--wrong cat test--" << std::endl << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound();
	meta2->makeSound();
	
	delete(meta);
	delete(i);
	delete(j);
	delete(meta2);
	delete(i2);
	return (0);
}
