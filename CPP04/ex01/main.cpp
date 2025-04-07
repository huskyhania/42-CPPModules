#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <new>

int main(void)
{
	/*{
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

	std::cout << std::endl << std::endl;

	delete(meta);
	delete(i);
	delete(j);
	}*/
	{
	std::cout << "--school main--" << std::endl;	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "-- between constructors and destructos --" << std::endl;
	delete j;
	delete i;
	}
	std::cout << std::endl << "--array test--" << std::endl;
	{
	Animal *pack[20];
	{
		for (int i = 0; i < 10; i++)
		{
			pack[i] = new Dog;
		}
		for (int i = 10; i < 20; i++)
		{
			pack[i] = new Cat;
		}
		for (int i = 0; i < 20; i++)
		{
			pack[i]->makeSound();
			delete pack[i];
		}
	}
	std::cout << std:: endl << "--copy test-- " << std::endl;
	Dog basic;
	{
		Dog temp = basic;
	}
	std::cout << std::endl << "--end test--" << std::endl;
	}
	//below is intentionally wrong test that will segfault due to shallow copy
	/*WrongCat test;
	{
		WrongCat copy = test;
		std::cout << "Let's see what happens" << std::endl;
	}
	std::cout << "Did we get here?" << std::endl;*/
	{
		std::cout << std::endl << "--brainiac test--" << std::endl << std::endl;
		Dog dogOne;
		Cat catOne;
		std::cout << "Doggy is starting to get ideas..." << std::endl;
		dogOne.think(0, "chasing ball");
		dogOne.think(1, "waaaalkies");
		dogOne.thinkOutLoud(0);
		dogOne.thinkOutLoud(1);
		std::cout << "Kitty is starting to get ideas..." << std::endl;
		catOne.think(0, "ball of yarn");
		catOne.think(1, "napping in the sun");
		catOne.thinkOutLoud(0);
		catOne.thinkOutLoud(1);
	}
	return (0);
}
