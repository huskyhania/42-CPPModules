/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:08:47 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/07/14 18:24:34 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>


// NEEDS A TEST FOR BIG NUMBERS

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	Span bigSpan(100);
	std::vector<int> newSpan = {1, 2, 3, 4, 5};
	try{	
		bigSpan.addRange(newSpan.begin(), newSpan.end());
		bigSpan.print();

		for (auto it = bigSpan.begin(); it != bigSpan.end(); ++it)
			std::cout << *it << std::endl;
		sp.addRange(newSpan.begin(), newSpan.end());
		for (auto it = sp.begin(); it != sp.end(); ++it)
			std::cout << *it << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something else went wrong...\n";
	}
	return 0;
}
