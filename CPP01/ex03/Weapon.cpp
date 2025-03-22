#include "Weapon.hpp"

Weapon::Weapon(){}

void Weapon::setType(std::string type)
{
	_type = type;
}

std::string Weapon::getType(void) const
{
	return _type;
}

Weapon::~Weapon();
