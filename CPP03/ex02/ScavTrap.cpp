/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:53:27 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/02 17:55:22 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("No name"){
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	maxHitPoints = 100;
	std::cout << "ScavTrap default constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name){
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	maxHitPoints = 100;
	std::cout << "ScavTrap parameter constructor called for " << name;
} 

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original){
	std::cout << "ScavTrap copy constructor called for " << name;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &original)
{
	std::cout << "ScavTrap overload assignment operator called" << std::endl << std::endl;
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

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called for " << name << std::endl;
}

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << name << " is in Gate keeper mode (what is it gatekeeping?)" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack due to lack of hit points" << std::endl;
	}
	else if (energyPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target 
			<< ", causing " << attackDamage << " points of damage" << std::endl;
			energyPoints--;
	}
	else if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " cannot attack due to lack of energy" << std::endl;
	}
}