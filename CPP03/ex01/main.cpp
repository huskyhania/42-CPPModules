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

int	main(void)
{
	ClapTrap Hans("Hans");
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
	Hans.takeDamage(10);

	
	return (0);
}
