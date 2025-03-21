/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:48:33 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/21 22:28:33 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	int N = 10;
	Zombie *horde = zombieHorde(N, "Jared");
	if (horde) {
		for (int i = 0; i < N; i++){
			horde[i].announce();
		}
		delete[]horde;
	}
	return (0);
}
