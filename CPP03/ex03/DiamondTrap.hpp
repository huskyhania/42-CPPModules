#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &original);
		~DiamondTrap();
		DiamondTrap &operator = (const DiamondTrap &original);

		void	attack(const std::string &target);
		void	whoAmI();
};

#endif
