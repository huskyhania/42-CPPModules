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

template <typename A> void increment(A& elem)
{
    elem = elem + 1;
}

int main(void)
{
	try{
	int int_arr[] = {2, 4, 8, 16, 32};
	char char_arr[] = { 'a', 'e', 'h', 'k', 'q', 'o'};
	float fl_arr[] = {0.2f, 0.89f, 0.11f, 0.9f};
	std::string str_arr[] = {"hello", "worlld", "!!!"};
	
	iter(int_arr, std::size(int_arr), print_info);
	iter(char_arr, std::size(char_arr), print_info);
	iter(fl_arr, std::size(fl_arr), print_info);
	iter(str_arr, std::size(str_arr), print_info);

	iter(int_arr, std::size(int_arr), increment<int>);
	iter(char_arr,  std::size(char_arr), increment<char>);
	iter(fl_arr, std::size(fl_arr), increment<float>);
	//iter(str_arr, 3, increment<std::string>);
	//try above for beautiful compilation errors due to trying to increment std::string

	std::cout << "-- after increment test -- " << std::endl;

	iter(int_arr, std::size(int_arr), print_info);
	iter(char_arr, std::size(char_arr), print_info);
	iter(fl_arr, std::size(fl_arr), print_info);
	iter(str_arr, std::size(str_arr), print_info);
	}
	catch (...)
	{
		std::cout << "something went wrong...";
	}
	return 0;
}