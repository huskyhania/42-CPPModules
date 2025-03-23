/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 21:23:32 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/23 22:10:28 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl test;

	std::cout << "testing debug" << std::endl;
	test.complain("DEBUG");
	std::cout << std::endl << "testing info" << std::endl;
	test.complain("INFO");
	std::cout << std::endl << "testing warning" << std::endl;
	test.complain("WARNING");
	std::cout << std::endl << "error" << std::endl;
	test.complain("ERROR");
	
	std::cout << std::endl << "invalid levels" << std::endl;
	test.complain("blabla");
	test.complain("");
	test.complain("      ");
	test.complain("...........");
	test.complain("who the fcuk is Harl?");
	return 0;
}
