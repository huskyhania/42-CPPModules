/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:20:50 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/21 23:35:41 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon
{
	private:
		std::string _type;
	public:
		const std::string &getType(void) const;
		void setType(std::string type);
		Weapon(std::string name);
		~Weapon();
};

#endif
