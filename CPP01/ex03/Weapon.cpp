#include "Weapon.hpp"

Weapon::Weapon(std::string name){
	_type = name;
};


void Weapon::setType(std::string type)
{
	_type = type;
}

const std::string &Weapon::getType(void) const
{
	return _type;
}

Weapon::~Weapon(){};
