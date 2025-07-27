/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:41:27 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/07/18 15:41:37 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <regex>
#include <exception>
#include <iomanip>

class BitcoinExchange
{
	private:
		std::map <std::string, float> database;
		bool isDateValid(std::string &date);
		bool isValueValid(std::string &value, float &output);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void useDatabase(std::ifstream& dataFile);
		void useInput(std::ifstream& inputFile);
};
