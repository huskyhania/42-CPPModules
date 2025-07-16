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
	{
		try
		{
		std::cout << "--test 1 (school main)--" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "--continuing with my test--" << std::endl;
		
		Span bigSpan(100);
		std::vector<int> newOne = {1, 2, 3, 4, 5};	
		bigSpan.addRange(newOne.begin(), newOne.end());
		bigSpan.print();

		sp.addRange(newOne.begin(), newOne.end());
		bigSpan.print();
		}
		catch (std::runtime_error &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "something else went wrong...\n";
		}
	}
	{
		try{
		std::cout << "--test 2 (add range)--" << std::endl;
		Span sp(10);

		std::vector<int> test = {1, 2, 3, 4, 5};
		sp.addRange(test.begin(), test.end());
		sp.print();
		sp.addNumber(6);
		sp.addNumber(10);
		sp.print();
		std::cout << sp.shortestSpan() << " --> shortest span of this range\n";
		std::cout << sp.longestSpan() << " --> longest span of this range\n";
		}	
		catch (std::runtime_error &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "something else went wrong...\n";
		}
	}
	{
		try{
			std::cout << "--test 3 (big one)--" << std::endl;
			Span bigSp(10999);
			std::vector<int> bigBoi(10089, 42);
			bigSp.addRange(bigBoi.begin(), bigBoi.end());
			//bigSp.print();
			std::vector<int> another(120, 43);
			bigSp.addRange(another.begin(), another.end());
			//bigSp.print(); this will spam with 42's...
			std::cout << "shortest span: " << bigSp.shortestSpan() << std::endl;
			std::cout << "longest span: " << bigSp.longestSpan() << std::endl;
			std::vector<int> another2(1200, 44);
			bigSp.addRange(another2.begin(), another2.end());// this must throw
			bigSp.print();
		}
		catch (std::runtime_error &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "something else went wrong...\n";
		}
	}
	{
		try{
			std::cout << "--test 4 (size too small)--" << std::endl;
			Span small(1);
			small.addNumber(1);
			std::cout  << small.shortestSpan() << "--shortest (error)--" << std::endl;
			std::cout  << small.longestSpan() << "--longest (error)--" << std::endl;
		}
		catch (std::runtime_error &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "something else went wrong...\n";
		}
	}
	return 0;
}
