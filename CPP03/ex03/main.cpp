/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:29:43 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/02 22:08:02 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include "DiamondTrap.hpp"

int	main(void)
{
	/*ClapTrap Hans("Hans");
	ClapTrap Henrik("Henrik");

	Hans.attack(Henrik.getName());
	Henrik.takeDamage(1);
	Henrik.beRepaired(1);
	Hans.attack(Henrik.getName());
	Henrik.takeDamage(10);
	Henrik.beRepaired(1);

	ClapTrap Helmut("Helmut");
	Helmut.attack(Hans.getName());
	Hans.takeDamage(10);
	Henrik.beRepaired(10);
	Henrik.beRepaired(10);
	Helmut.attack(Hans.getName());
	Hans.takeDamage(10);*/
	
	std::cout << "constructor test\n";
	ClapTrap();
	ScavTrap();
	FragTrap();
	DiamondTrap();
	std::cout << "\nend constructor test\n";

	DiamondTrap();
	DiamondTrap Dave("Dave");
	DiamondTrap David("David");
	std::cout << std::endl << std::endl << "--DiamondTrap tests--" << std::endl << std::endl;
	std::cout << Dave.getName() << " energy: " << Dave.getEnergyPoints() << "hit points: " << Dave.getHitPoints() << std::endl; 
	Dave.beRepaired(0);
	std::cout << " energy: " << Dave.getEnergyPoints();
	Dave.attack(David.getName());
	David.takeDamage(20);
	David.attack(Dave.getName());

	David.whoAmI();
	std::cout << std::endl << std::endl;

	
	return (0);
}
