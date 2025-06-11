/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:07:31 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/06/08 14:07:33 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename A> void	print_info(const A &value)
{
	std::cout << "Value: " << value << " | Type: " << typeid(value).name() << std::endl;
}

template <typename A> void increment(A& elem) {
    elem = elem + 1;
	//std::cout << "elem from double value: " << elem << std::endl;
}

int main(void)
{
	int int_arr[] = {2, 4, 8, 16, 32};
	char char_arr[] = { 'a', 'e', 'h', 'k', 'q', 'o'};
	float fl_arr[] = {0.2f, 0.89f, 0.11f, 0.9f};
	
	iter(int_arr, 5, print_info);
	iter(char_arr, 6, print_info);
	iter(fl_arr, 4, print_info);

	iter(int_arr, 5, increment<int>);
	iter(char_arr, 6, increment<char>);
	iter(fl_arr, 4, increment<float>);

	std::cout << "-- after increment test -- " << std::endl;

	iter(int_arr, 5, print_info);
	iter(char_arr, 6, print_info);
	iter(fl_arr, 4, print_info);
	
	return 0;
}