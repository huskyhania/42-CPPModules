#include "Zombie.hpp"
#include <new>
#include <iostream>

Zombie* newZombie(std::string name)
{
	try{
		Zombie *undead = new Zombie(name);
		return (undead);
	}
	catch (std::bad_alloc& e){
		std::cerr << "Memory allocation failed:" << std::endl;
		return nullptr;
	}
}
