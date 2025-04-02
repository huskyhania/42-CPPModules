/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:29:43 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/01 22:36:29 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	
	ScavTrap Sven("Sven");
	ScavTrap Sigmund("Sigmund");
	std::cout << std::endl << std::endl << "--ScavTrap tests--" << std::endl << std::endl;
	Sven.attack(Sigmund.getName());
	Sigmund.takeDamage(20);
	Sigmund.attack(Sven.getName());

	Sven.guardGate();
	std::cout << std::endl << std::endl;
	FragTrap Troy("Troy");
	std::cout << std::endl << std::endl << "--FragTrap tests--" << std::endl << std::endl;
	Troy.attack(Sven.getName());
	Troy.highFivesGuys();
	std::cout << std::endl << std::endl;
	return (0);
}
