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

bool	isChar(const std::string &s)
{
	return s.length() == 1 && std::isprint(s[0])
		&& !std::isdigit(s[0]);
}

bool	isInt(const std::string &s)
{
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') i++;
	if (i == s.size()) return false;
	while (i < s.size())
	{
		if (!std::isdigit(s[i])) return false;
		++i;
	}
	return true;
}

bool	isFloat(const std::string &s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff") return true;
	size_t i = 0;
	bool dotSeen = false;
	if (s[i] == '+' || s[i] == '-') i++;
	for (; i < s.size() - 1; ++i) {
		if (s[i] == '.') {
			if (dotSeen) return false;
			dotSeen = true;
		} 
		else if (!std::isdigit(s[i]))
		{
			return false;
		}
	}
	return s.back() == 'f' && dotSeen;
}

bool	isDouble(const std::string &s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return true;
	size_t i = 0;
	bool dotSeen = false;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; i < s.size(); ++i)
	{
		if (s[i] == '.')
		{
			if (dotSeen)
				return false;
			dotSeen = true;
		}
		else if (!std::isdigit(s[i]))
		{
			return false;
		}
	}
	return dotSeen;
}
