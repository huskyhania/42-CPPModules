#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon1;
	public:
		void	attack(void);
		void	setWeapon(Weapon &newWeapon);
		HumanB(std::string nameB);
		~HumanB();
};

#endif