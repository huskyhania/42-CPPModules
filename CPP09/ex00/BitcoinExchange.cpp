/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 13:51:30 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/07/27 13:52:06 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& org)
    : database(org.database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& org)
{
    if (this != &org)
    {
        database = org.database;
    }
    return *this;
}

bool BitcoinExchange::isDateValid(std::string &date)
{
	static const std::regex pattern(R"(^\d{4}-\d{2}-\d{2}$)");
	if (!std::regex_match(date, pattern))
		return false;

	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));

	if (year < 2009 || year > 2025)
		return false;
	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

void BitcoinExchange::useDatabase(std::ifstream& dataFile)
{
	std::string line;
	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		size_t commaPos = line.find(",");
		if (commaPos == std::string::npos)
		{
			std::cerr << "Error: invalid line (no comma): " << line << std::endl;
			continue;
		}
		try
		{
			std::string date = line.substr(0, commaPos);
			std::string valueStr = line.substr(commaPos + 1);
			if (!isDateValid(date)) 
				throw std::runtime_error("Error: date error in line " + line);
			float value = std::stof(valueStr);
			database[date] = value;
		} 
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::useInput(std::ifstream& inputFile)
{
	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string pipe;
		std::string valueStr;
		if (!(iss >> date >> pipe >> valueStr))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (pipe != "|")
		{
			std::cerr << "Error: expected '|', found '" << pipe << "' in line: " << line << std::endl;
			continue;
		}
		if (!isDateValid(date))
		{
			std::cerr << "Error: invalid date: " << date << " in line: " << line << std::endl;
			continue;
		}
		float inputValue;
		try
		{
			inputValue = std::stof(valueStr);
			if (inputValue < 0)
			{
				std::cerr << "Error: not a positive number. " << std::endl;
				continue;
			}
			if (inputValue > 1000)
			{
				std::cerr << "Error: too large a number. " << std::endl;
				continue;
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: conversion to float failed in line: " << line << std::endl;
			continue;
		}
		auto it = database.lower_bound(date);
		if (it == database.end() || it->first != date)
		{
			if (it == database.begin())
			{
				std::cerr << "Error: no data available for date or earlier: " << date << std::endl;
				continue;
			}
			--it;
		}

		float rate = it->second;
		float result = inputValue * rate;

		std::cout << date << " => " << inputValue << " = " << result << std::endl;
	}
}