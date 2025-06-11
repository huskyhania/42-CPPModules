/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:13:56 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/06/07 21:20:35 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main(void)
{
	{
		std::cout << "--test 1--\n";
		int a = 5;
		int b = 3;
		std::cout << "a: " << a << " and b: " << b << std::endl;
		std::cout << "calling swap... \n";
		swap<int>(a, b);
		std::cout << "a: " << a << " and b: " << b << std::endl;
	}
	{
		std::cout << "--test 2--\n";
		char a = 'A';
		char b = 'B';
		std::cout << "a: " << a << " and b: " << b << std::endl;
		std::cout << "calling swap... \n";
		swap<char>(a, b);
		std::cout << "a: " << a << " and b: " << b << std::endl;
	}
	{
		std::cout << "--test 3--\n";
		float a = 4.5f;
		float b = 3.0f;
		std::cout << "a: " << a << " and b: " << b << std::endl;
		std::cout << "calling swap... \n";
		swap<float>(a, b);
		std::cout << "a: " << a << " and b: " << b << std::endl;
	}
	{
		std::cout << "--test 4--\n";
		int a = 5;
		int b = 3;
		std::cout << "a: " << a << " and b: " << b << std::endl;
		std::cout << "calling max... \n";
		int bigger = max<int>(a, b);
		std::cout << "bigger of the two is... : " << bigger << std::endl;
	}
	{
		std::cout << "--test 5--\n";
		char a = 'A';
		char b = 'B';
		std::cout << "a: " << a << " and b: " << b << std::endl;
		std::cout << "calling max... \n";
		char bigger = max<char>(a, b);
		std::cout << "bigger of the two is... : " << bigger << std::endl;
	}
	{
		std::cout << "--test 6--\n";
		float a = 4.5f;
		float b = 3.0f;
		std::cout << "a: " << a << " and b: " << b << std::endl;
		std::cout << "calling max... \n";
		float bigger = max<float>(a, b);
		std::cout << "bigger of the two is... : " << bigger << std::endl;
	}
	{
		std::cout << "--test 7--\n";
		int a = 5;
		int b = 3;
		std::cout << "a: " << a << " and b: " << b << std::endl;
		std::cout << "calling min... \n";
		int smaller = min<int>(a, b);
		std::cout << "smaller of the two is... : " << smaller << std::endl;
	}
	{
		std::cout << "--test 8--\n";
		char a = 'A';
		char b = 'B';
		std::cout << "a: " << a << " and b: " << b << std::endl;
		std::cout << "calling min... \n";
		char smaller = min<char>(a, b);
		std::cout << "smaller of the two is... : " << smaller << std::endl;
	}
	{
		std::cout << "--test 9--\n";
		float a = 4.5f;
		float b = 3.0f;
		std::cout << "a: " << a << " and b: " << b << std::endl;
		std::cout << "calling min... \n";
		float smaller = min<float>(a, b);
		std::cout << "smaller of the two is... : " << smaller << std::endl;
	}
	{
		std::cout << "--school main--\n";
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return 0;
}
