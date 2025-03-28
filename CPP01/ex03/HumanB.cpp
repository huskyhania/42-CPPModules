#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string nameB)
{
	_name = nameB;
	_weapon1 = nullptr;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	_weapon1 = &newWeapon;
}

void	HumanB::attack()
{
	std::cout << _name << " attacks with their "; 
	if (_weapon1 == nullptr)
		std::cout << "best intentions" << std::endl;
	else 
		std::cout << _weapon1->getType() << std::endl;
}

HumanB::~HumanB(){}
