/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:23:32 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/23 22:51:57 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Please give one parameter, ideally a number" << std::endl;
		return 1;
	}
	
	
	int level;
	try
	{
		level = std::stoi(argv[1]);
	}
	catch (...)
	{
		level = 0;
	}
	Harl test;
	switch(level)
	{
		case 1:
			std::cout << "[ DEBUG ]" << std::endl;
			test.complain("DEBUG");
			//test.complain("INFO");
			//test.complain("WARNING");
			//test.complain("ERROR");
			//break;
			[[fallthrough]];
		case 2:
			std::cout << "[ INFO ]" << std::endl;
			test.complain("INFO");
			//test.complain("WARNING");
 			//test.complain("ERROR");
			//break;
			[[fallthrough]];
		case 3:
			std::cout << "[ WARNING ]" << std::endl;
			test.complain("WARNING");
			//test.complain("ERROR");
			//break;
			[[fallthrough]];
		case 4:
			std::cout << "[ ERROR ]" << std::endl;
			test.complain("ERROR");
			break;
		default:
			test.complain("???");
	}
	return 0;
}
