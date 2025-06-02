/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:16:50 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/06/02 18:16:57 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	try
	{
		Data* data1 = new Data();
		std::cout << "original strings: " << data1->something
		<< " " << data1->something2 << " " << data1->something3 << std::endl;
		std::cout << "address stored: " << data1 << std::endl;
		uintptr_t sth = Serializer::serialize(data1);
		std::cout << "Raw serialized value (uintptr_t): " << sth << std::endl;
		std::cout << "serialized value as pointer: " << reinterpret_cast<void*>(sth) << std::endl;
		Data *data3 = Serializer::deserialize(sth);
		std::cout << "strings in a deserialized guy: " << data3->something
		<< " " << data3->something2 << " " << data3->something3 << std::endl;
		std::cout << "address stored: " << data3 << std::endl;
		delete data1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}