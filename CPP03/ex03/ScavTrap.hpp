#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap{
	public:
		const static unsigned int startHitPoints = 100;
		const static unsigned int startEnergyPoints = 50;
		const static unsigned int startAttackDamage = 20;
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &original);
		~ScavTrap();
		ScavTrap &operator = (const ScavTrap &original);
		void guardGate();
		void attack(const std::string& target) override;
		unsigned int getStartHitPoints() const override;
};
#endif
