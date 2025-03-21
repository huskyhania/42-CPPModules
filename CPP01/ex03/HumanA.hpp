/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:57:09 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/22 01:02:52 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP
#define HumanA_HPP

class HumanA
{
	private:
		std::string _name;
	public:
		Weapon Weapon1;
		void	attack();
		HumanA();//should take a weapon in its contructor
		~HumanA();
};

#endif
