/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:57:09 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/26 16:31:53 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP
#define HumanA_HPP
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon& Weapon1;
	public:
		void	attack();
		HumanA(std::string nameA, Weapon& weaponA);
};

#endif
