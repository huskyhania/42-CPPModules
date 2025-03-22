/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:00:44 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/22 01:01:59 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon& Weapon1;
	public:
		void	attack();
		HumanB(std::string nameB);
		HumanB(std::string nameB, Weapon& weaponB);
		~HumanB();
};

#endif
