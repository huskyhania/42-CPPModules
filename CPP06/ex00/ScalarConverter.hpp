/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:44:58 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/25 18:23:47 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

typedef enum types
{
	INVALID,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}	strType;

class ScalarConverter
{
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &original) = delete;
		ScalarConverter &operator=(ScalarConverter &soriginal) = delete;
		~ScalarConverter() = delete;
	public:
		static void convert(std::string toConvert);
};

#endif
