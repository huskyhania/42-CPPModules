/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:57:59 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/21 22:21:25 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
		return nullptr;
	try{
		Zombie *horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			horde[i].setName(name + std::to_string(i + 1));
		return (horde);
	}
	catch (std::bad_alloc& e){
		std::cerr << "Memory allocation failed:" << std::endl;
		return nullptr;
	}
}
