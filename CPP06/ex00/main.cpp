/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:24:46 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/05/25 17:25:14 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//static cast for ex00, reinterpret for ex01, dynamic for ex02
//nan, inf, -inf - special floating-point values used in numerical computing
//to represent results of certain undefined or unrepresentable mathematical operations

//nan - not a number, result of undefined or unrepresentable maths
//eg. dividing zero by zero, multiplying infinity by 0 (inf * 0)
//square root of negative number, subracting infinity from infinity

//inf (infinity) - represents the result of math op that yields an infinitely large outcome
//dividing a non-zero number by zeo
//multiplying infinity by a non-zero
//adding or substracting infinity to or from a finite number
//can be positive or negative

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Please give give one argument" << std::endl;
	// else
	// {
	// 	std::cout << "--simple char--" << std::endl;
	// 	std::string test = "a";
	// 	std::string test1 = "z";
	// 	ScalarConverter::convert(test);
	// 	ScalarConverter::convert(test1);
	// 	std::cout << "--simple int--" << std::endl;
	// 	std::string test2 = "0";
	// 	std::string test3 = "-42";
	// 	ScalarConverter::convert(test);
	// 	ScalarConverter::convert(test1);
	// }
	return 0;
}