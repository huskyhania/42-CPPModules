#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
	public:
		const static unsigned int startHitPoints = 10;
		const static unsigned int startEnergyPoints = 10;
		const static unsigned int startAttackDamage = 0;
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &original);
		virtual ~ClapTrap();
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		ClapTrap &operator = (const ClapTrap &original);
		std::string getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
};

#endif
