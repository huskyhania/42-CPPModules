/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:48:33 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/28 15:55:47 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 10; //test with N = 1000000000 to see new[] fail
	Zombie *horde = zombieHorde(N, "Jared");
	if (horde) {
		for (int i = 0; i < N; i++){
			horde[i].announce();
		}
		delete[]horde;
	}
	N = 0;
 	Zombie *testzero = zombieHorde(N, "Jared");
	if (testzero) {
		for (int i = 0; i < N; i++){
			testzero[i].announce();
		}
		delete[]testzero;
	}
	return (0);
}
