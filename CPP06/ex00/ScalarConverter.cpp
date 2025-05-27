/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:44:47 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/25 17:44:49 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	isChar(const std::string &s)
{
	if (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
		return CHAR;
	return INVALID;	
}

int	isInt(const std::string &s)
{
	size_t i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.size())
		return INVALID;
	if (s.find_first_not_of("0123456789", i) != std::string::npos)
		return INVALID;
	return (INT);
}

int	isFloat(const std::string &s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return FLOAT;
	
	size_t i = 0;
	bool hasDot = false;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; i < s.size() - 1; ++i)
	{
		if (s[i] == '.')
		{
			if (hasDot) 
				return INVALID;
			hasDot = true;
		} 
		else if (!std::isdigit(s[i]))
			return INVALID;
	}
	if (s.back() == 'f' && hasDot)
		return FLOAT;
	return INVALID;
}

int	isDouble(const std::string &s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return DOUBLE;
	size_t i = 0;
	bool hasDot = false;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; i < s.size(); ++i)
	{
		if (s[i] == '.')
		{
			if (hasDot)
				return INVALID;
			hasDot = true;
		}
		else if (!std::isdigit(s[i]))
			return INVALID;
	}
	return DOUBLE;
}

int findType(const std::string &s)
{
	int (*detectors[])(const std::string &) = { isChar, isInt, isFloat, isDouble };
	for (int i = 0; i < 4; ++i)
	{
		int type = detectors[i](s);
		if (type != INVALID)
			return type;
	}
	return INVALID;
}

void printChar(const std::string &s)
{
	char c = s[0];
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void printInt(const std::string &s)
{
	try{
		int i = std::stoi(s);
		char c = static_cast<char>(i);
		std::cout << "char: ";
		if (std::isprint(c))
			std::cout << "'" << c << "'\n";
		else
			std::cout << "Non displayable\n";
		std::cout << "int: " << i << "\n";
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
		std::cout << "double: " << static_cast<double>(i) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "overflow detected" << std::endl;
	}
}

void printFloat(const std::string &s) {
	try{
		float f = std::stof(s);
		std::cout << "char: ";
		if (std::isnan(f) || std::isinf(f))
			std::cout << "impossible\n";
		else if (std::isprint(static_cast<char>(f)))
			std::cout << "'" << static_cast<char>(f) << "'\n";
		else
			std::cout << "Non displayable\n";
		std::cout << "int: ";
		if (std::isnan(f) || std::isinf(f))
			std::cout << "impossible\n";
		else
			std::cout << static_cast<int>(f) << "\n";
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
		std::cout << "double: " << static_cast<double>(f) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "overflow detected" << std::endl;
	}
}

void printDouble(const std::string &s) {
	try{
		double d = std::stod(s);
		std::cout << "char: ";
		if (std::isnan(d) || std::isinf(d))
			std::cout << "impossible\n";
		else if (std::isprint(static_cast<char>(d)))
			std::cout << "'" << static_cast<char>(d) << "'\n";
		else
			std::cout << "Non displayable\n";

		std::cout << "int: ";
		if (std::isnan(d) || std::isinf(d))
			std::cout << "impossible\n";
		else
			std::cout << static_cast<int>(d) << "\n";
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
		std::cout << "double: " << d << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << "overflow detected" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string toConvert)
{
	int type = findType(toConvert);
	switch (type){
		case CHAR:
			printChar(toConvert);
			break;
		case INT:
			printInt(toConvert);
			break;
		case FLOAT:
			printFloat(toConvert);
			break;
		case DOUBLE:
			printDouble(toConvert);
			break;
		default:
			std::cout << "Please give a valid string" << std::endl;
	}
}