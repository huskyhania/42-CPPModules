/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:15:49 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/06/02 18:15:51 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data* ptr)
{
	std::cout << "serialize called\n";
	return reinterpret_cast<std::uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	std::cout << "deserialize called\n";
	return reinterpret_cast<Data *>(raw);
}