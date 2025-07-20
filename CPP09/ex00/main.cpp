/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:16:09 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/07/18 15:33:14 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include "BitcoinExchange.hpp"
#include <filesystem>
#include <fstream>

int check_input(char *filename)
{
	if (std::filesystem::path(filename).extension() != ".txt")
		throw(std::runtime_error("Invalid file extension"));
	std::ifstream file(filename);
	if (!file.is_open())
		throw(std::runtime_error("No permissions to open file"));
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\033[31mWrong usage\033[0m" << std::endl;
		std::cout << "Please run the program with one input file in txt format" << std::endl;
	}
	else
	{
		try
		{
			check_input(argv[1]);
			//checkRates();
		}
		catch (std::runtime_error &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
