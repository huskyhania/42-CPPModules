/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:34:48 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/06/02 18:35:44 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data
{
	public:
		std::string something;
		std::string something2;
		std::string something3;
		Data();
		Data(const Data &original);
		Data &operator=(const Data &original);
		~Data();		
};

#endif
