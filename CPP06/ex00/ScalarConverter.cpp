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

void printInt(const std::string &s, int overflowInfo)
{
	try
	{
		int i = std::stoi(s);
		if (overflowInfo)
			std::cout << "char: impossible\n";
		else
		{
			char c = static_cast<char>(i);
			std::cout << "char: ";
			if (std::isprint(c))
				std::cout << "'" << c << "'\n";
			else
				std::cout << "Non displayable\n";
		}
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
		std::cout << "double: " << static_cast<double>(i) << "\n";
	}
	catch(std::out_of_range)
	{
		std::cout << "int overflow\nchar: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	}
	catch(...)
	{
		std::cout << "something else went wrong...\n";
	}
}

void printFloat(const std::string &s, int overflowInfo) {
	try
	{
		float f = std::stof(s);
		std::cout << "char: ";
		if (std::isnan(f) || std::isinf(f) || overflowInfo)
			std::cout << "impossible\n";
		else if (std::isprint(static_cast<char>(f)))
			std::cout << "'" << static_cast<char>(f) << "'\n";
		else
			std::cout << "Non displayable\n";
		std::cout << "int: ";
		if (std::isnan(f) || std::isinf(f) || overflowInfo == 2)
			std::cout << "impossible\n";
		else
			std::cout << static_cast<int>(f) << "\n";
		if (overflowInfo == 3)
			std::cout << "float: impossible\n";
		else 
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
		std::cout << "double: " << f << "\n";
	}
	catch (std::out_of_range &)
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	}
	catch (...)
	{
		std::cout << "something else went wrong" << std::endl;
	}
}

void printDouble(const std::string &s, int overflowInfo) {
	try{
		double d = std::stod(s);
		std::cout << "char: ";
		if (std::isnan(d) || std::isinf(d) || overflowInfo)
			std::cout << "impossible\n";
		else if (std::isprint(static_cast<char>(d)))
			std::cout << "'" << static_cast<char>(d) << "'\n";
		else
			std::cout << "Non displayable\n";
		std::cout << "int: ";
		if (std::isnan(d) || std::isinf(d) || overflowInfo > 1)
			std::cout << "impossible\n";
		else
			std::cout << static_cast<int>(d) << "\n";
		if (overflowInfo < 3)
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
		else
			std::cout << "float: impossible\n";
		std::cout << "double: " << d << "\n";
	}
	catch (std::out_of_range &)
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	}
	catch (...)
	{
		std::cout << "something else went wrong..." << std::endl;
	}
}
int	isOverflow(double temp)
{
	if (temp < -std::numeric_limits<float>::max() || temp > std::numeric_limits<float>::max())
        return 3;
	if (temp < static_cast<double>(std::numeric_limits<int>::min()) || temp > static_cast<double>(std::numeric_limits<int>::max()))
        return 2;
	if (temp < static_cast<double>(std::numeric_limits<char>::min()) || temp > static_cast<double>(std::numeric_limits<char>::max()))
        return 1;
	return 0;
}

void	ScalarConverter::convert(const std::string toConvert)
{
	int type = findType(toConvert);
	std::cout << "type from find type is: " << type << std::endl;
	int overflowInfo = 0;
	if (type != CHAR && type != INVALID)
	{
		double temp = std::stod(toConvert);
		overflowInfo = isOverflow(temp);
		std::cout << overflowInfo << " overflow check result\n";
	}
	switch (type){
		case CHAR:
			printChar(toConvert);
			break;
		case INT:
			printInt(toConvert, overflowInfo);
			break;
		case FLOAT:
			printFloat(toConvert, overflowInfo);
			break;
		case DOUBLE:
			printDouble(toConvert, overflowInfo);
			break;
		default:
			std::cout << "Please give a valid string" << std::endl;
	}
}
