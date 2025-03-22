#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string nameB)
{
	_name = nameB;
}

HumanB::HumanB(std::string nameB, Weapon& weaponB) : _name(nameB), Weapon1(weaponB){}

void	HumanB::attack()
{
	std::cout << " attacks with their " << Weapon1.getType() << std::endl;
}

HumanB::~HumanB(){}
