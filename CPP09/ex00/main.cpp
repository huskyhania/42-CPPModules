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

#include "BitcoinExchange.hpp"
#include <filesystem>

void validate_extension(const char *filename, const char *ext)
{
	if (std::filesystem::path(filename).extension() != ext)
		throw(std::runtime_error("Invalid file extension"));
}

void open_file(std::ifstream &file, const char *filename)
{
	file.open(filename);
	if (!file.is_open())
		throw(std::runtime_error("No permissions to open file"));
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\033[31mWrong usage\033[0m" << std::endl;
		std::cout << "Please run the program with one input file in txt format" << std::endl;
	}
	std::ifstream csv_file;
	std::ifstream input_file;
	try
	{
		validate_extension("data.csv", ".csv");
		open_file(csv_file, "data.csv");
		validate_extension(argv[1], ".txt");
		open_file(input_file, argv[1]);
		BitcoinExchange btc;
		btc.useDatabase(csv_file);
		btc.useInput(input_file);
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
