#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <new>

int main(void)
{
	std::cout << std::endl << "--school main--" << std::endl << std::endl;
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	delete(j);
	delete(i);

	std::cout << std::endl << "final abstract test" << std::endl;
	Animal *a = new Dog();
	std::cout << std::endl;
	a->makeSound();
	delete(a);
	std::cout << "--end test--" << std::endl;

	/*error test - will result in compiler errors:
	const Animal* meta = new Animal();
	meta->makeSound();
	delete(meta);*/
	return (0);
}
