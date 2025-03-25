/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:23:32 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/25 21:18:26 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	lvlFromString(const std::string &level)
{
	const std::string scale[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == scale[i])
			return (i + 1);
	}
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Please give one parameter, ideally a number or a complaint type" << std::endl;
		return 1;
	}
	
	
	int level;
	try
	{
		level = std::stoi(argv[1]);
	}
	catch (...)
	{
		level = lvlFromString(argv[1]);
	}
	Harl test;
	switch(level)
	{
		case 1:
			std::cout << "[ DEBUG ]" << std::endl;
			test.complain("DEBUG");
			[[fallthrough]];
		case 2:
			std::cout << "[ INFO ]" << std::endl;
			test.complain("INFO");
			[[fallthrough]];
		case 3:
			std::cout << "[ WARNING ]" << std::endl;
			test.complain("WARNING");
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
