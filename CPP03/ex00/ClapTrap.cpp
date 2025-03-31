#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("No name"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &original) : name(original.name), hitPoints(original.hitPoints), energyPoints(original.energyPoints), attackDamage(original.attackDamage)
{
	std::cout << "copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &original)
{
	std::cout << "overload assignment operator called" << std::endl;
	if (this != &original)
	{
		name = orginal.name;
		hitPoints = original.hitPoints;
		energyPoints = original.energyPoints;
		attackDamage = attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called" << std::endl;
}
