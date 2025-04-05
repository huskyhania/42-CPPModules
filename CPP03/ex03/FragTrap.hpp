#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap{
	public:
		const static unsigned int startHitPoints = 100;
		const static unsigned int startEnergyPoints = 100;
		const static unsigned int startAttackDamage = 30;
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &original);
		~FragTrap();
		FragTrap &operator = (const FragTrap &original);

		void	attack(const std::string& target) override;
		unsigned int getStartHitPoints() const override;
		
		void	highFivesGuys(void);

};

#endif
