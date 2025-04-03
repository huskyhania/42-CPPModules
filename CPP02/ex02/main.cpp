/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:41:05 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/29 21:42:54 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a,b ) << std::endl;


	//my tests
	std::cout << std::endl;
	std::cout << "--MY TESTS--" << std::endl << std::endl;
	Fixed test1;
	Fixed test2(10);
	Fixed const test3(77.77f);
	Fixed const test4(test2);
	Fixed const test5(test3);
	Fixed test6(1.33f);
	std::cout << "test 1 is " << test1 << std::endl;
	std::cout << "multiplying ints: " << test2 << " & " << test4 << std::endl << test2 * test4 << std::endl;
	std::cout << "multiplying int by float: " << test2 << " & " << test3 << std::endl << test2 * test3 << std::endl;
	std::cout << "division test " << test2 << " & " << test4 << std::endl << test2 / test4 << std::endl;
	std::cout << "division int by float " << test2 << " & " << test6 << std::endl << test2 / test6 << std::endl;
	std::cout << "adding int to float: " << test2 << " & " << test6 << std::endl << test2 + test6 << std::endl;
	std::cout << "subtracting float from int: " << test2 << " & " << test6 << std::endl << test2 - test6 << std::endl;
	std::cout << "subtracting int from float: " << test3 << " & " << test2 << std::endl << test3 - test2 << std::endl;

	test1 = Fixed(11.11f);
	
	std::cout << std::endl << "--post/pre increment tests--" << std::endl;
	std::cout << "test 1 new value: " << test1 << std::endl;
	std::cout << "test1++: " << test1++ << std::endl;
	std::cout << "test 1 new value: " << test1 << std::endl;
	std::cout << "--test1: " << --test1 << " --test: " << --test1 << std::endl;
	std::cout << "test2: " << test2 << std::endl;
	std::cout << "test2++: " << test2++ << " new value of test2: " << test2 << std::endl;
	std::cout << "test2--: " << test2-- << std::endl;
	std::cout << "--test2: " << --test2 << std::endl;
	std::cout << "++test2: " << ++test2 << std::endl;

	std::cout << std::endl << "--comparison tests--" << std::endl;
	Fixed val1(5);
	Fixed val2(5.33f);
	Fixed val3(5);
	std::cout << "Comparing val1 " << val1 << ", val2 " << val2 << " and val3 " << val3 << std::endl;
	std::cout << "val1 < val2 " << (val1 < val2) << std::endl;
	std::cout << "val1 > val2 " << (val1 > val2) << std::endl;
	std::cout << "val1 <= val2 " << (val1 <= val2) << std::endl;
	std::cout << "val1 >= val2 " << (val1 >= val2) << std::endl;
	std::cout << "val1 == val3 " << (val1 == val3) << std::endl;
	std::cout << "val1 != val3 " << (val1 != val3) << std::endl;
	std::cout << "val2 >= val3 " << (val2 >= val3) << std::endl;
	std::cout << "val1 >= val3 " << (val1 >= val3) << std::endl;
	
	std::cout << std::endl << "--min/max tests--" << std::endl;
	std::cout << "returning bigger one of " << test2 << " & " << test6 << std::endl << Fixed::max( test2, test6 ) << std::endl;
	std::cout << "returning smaller one of " << test2 << " & " << test6 << std::endl << Fixed::min( test2, test6 ) << std::endl;
	std::cout << "returning (fixed) bigger one of " << test3 << " & " << test4 << std::endl << Fixed::max( test3, test4 ) << std::endl;
	std::cout << "returning (fixed) smaller one of " << test3 << " & " << test4 << std::endl << Fixed::min( test4, test4 ) << std::endl;
	//if you try calling min or max on const numbers without the const functions it won't compile
	//if one of the values is const, the const function will be called
	return 0;
}
