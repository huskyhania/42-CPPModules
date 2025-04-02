/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:36:54 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/02 21:37:09 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("NoName_clap_name"), name("NoName"){
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	maxHitPoints = 100;
	std::cout << "DiamondTrap default constructor called for " << name;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), name(name){
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	maxHitPoints = 100;
	std::cout << "DiamondTrap parameter constructor called for " << name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original) : ClapTrap(original), ScavTrap(original), FragTrap(original), name(original.name){
	std::cout << "DiamondTrap copy constructor called for " << name;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &original)
{
	std::cout << "DiamondTrap overload assignment operator called" << std::endl << std::endl;
	if (this != &original)
	{
		name = original.name;
		hitPoints = original.hitPoints;
		energyPoints = original.energyPoints;
		attackDamage = original.attackDamage;
		maxHitPoints = original.maxHitPoints;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void){
	std::cout << "Hello? Is it DiamondTrap you're looking for...?" << std::endl;
	std::cout << "My DiamondTrap name is " << name << std::endl;
	std::cout << "Base ClapTrap name is " << ClapTrap::name << std::endl;
}

