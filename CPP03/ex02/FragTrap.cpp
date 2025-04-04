/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:21:02 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/02 20:57:45 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("No name"){
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	maxHitPoints = 100;
	std::cout << "FragTrap default constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name){
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	maxHitPoints = 100;
	std::cout << "FragTrap parameter constructor called for " << name;
} 

FragTrap::FragTrap(const FragTrap &original) : ClapTrap(original){
	std::cout << "FragTrap copy constructor called for " << name;
}

FragTrap &FragTrap::operator = (const FragTrap &original)
{
	std::cout << "FragTrap overload assignment operator called" << std::endl << std::endl;
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

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called for " << name << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap " << name << " cannot attack due to lack of hit points" << std::endl;
	}
	else if (energyPoints > 0)
	{
		std::cout << "FragTrap " << name << " attacks " << target 
			<< ", causing " << attackDamage << " points of damage" << std::endl;
			energyPoints--;
	}
	else if (energyPoints == 0)
	{
		std::cout << "FragTrap " << name << " cannot attack due to lack of energy" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void){
	std::cout << "Give it here for FragTrap " << name << " *HIGH FIVE* " << std::endl;
}
