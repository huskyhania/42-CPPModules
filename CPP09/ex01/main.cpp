/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:44:42 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/07/27 16:45:18 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		std::cerr << "Usage error - use one argument only" << std::endl;
		return 1;
	}
	try
	{
		reverseMe(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Something went wrong..." << std::endl;
	}
	return 0;
}
