/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:51:07 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/06/02 19:00:05 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	something = "test";
	something2 = "test2";
	something3 = "test3";
	//std::cout << "deffo constructor" << std::endl;
}

Data::Data(const Data &original) : 
	something(original.something),
	something2(original.something2),
	something3(original.something3)
{
	//std::cout << "copy constructor" << std::endl;
}

Data &Data::operator=(const Data &original)
{
	//std::cout << "assignement operator" << std::endl
	if (this != &original)
	{
		something = original.something;
		something2 = original.something2;
		something3 = original.something3;
	}
	return (*this);
}

Data::~Data()
{
	//std::cout << "destructor" << std::endl;
}
