#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

//has to have different messages from constr/destr and attack
class ScavTrap: public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &original);
		~ScavTrap();
		ScavTrap &operator = (const ScavTrap &original);
		void guardGate();
		void attack(const std::string& target) override; 
};

#endif
