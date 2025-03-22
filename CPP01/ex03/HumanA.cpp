#include "HumanA.hpp"
#include <iostream>
#include "Weapon.hpp"

HumanA::HumanA(std::string nameA, Weapon& weaponA) : _name(nameA), Weapon1(weaponA){}

void	HumanA::attack()
{
	std::cout << " attacks with their " << Weapon1.getType() << std::endl;
}

HumanA::~HumanA(){}
