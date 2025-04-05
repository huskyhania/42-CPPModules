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
	hitPoints = FragTrap::startHitPoints;
	energyPoints = ScavTrap::startEnergyPoints;
	attackDamage = FragTrap::startAttackDamage;
	std::cout << "DiamondTrap default constructor called for " << name;
	std::cout << "values are: " << this->hitPoints << " " << this->energyPoints << " " << this->attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), name(name){
	hitPoints = FragTrap::startHitPoints;
	energyPoints = ScavTrap::startEnergyPoints;
	attackDamage = FragTrap::startAttackDamage;	
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

unsigned int	DiamondTrap::getStartHitPoints() const
{
	return ScavTrap::getStartHitPoints();
}

std::string	DiamondTrap::getName() const
{
	return name;
}

void	DiamondTrap::whoAmI(void){
	std::cout << "Hello? Is it DiamondTrap you're looking for...?" << std::endl;
	std::cout << "My DiamondTrap name is " << name << std::endl;
	std::cout << "Base ClapTrap name is " << ClapTrap::name << std::endl;
}

