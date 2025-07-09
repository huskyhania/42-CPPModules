/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:28:14 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/07/09 19:29:13 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <forward_list>

int main(void)
{
	std::cout << "--test 1 (vector)--" << std::endl;
	try
	{
		std::vector<int> intVector = {99, 0, -1, 1, 101};
		auto searched = easyfind(intVector, 1);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
		searched = easyfind(intVector, -11111);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something went wrong" << std::endl;
	}
	std::cout << std::endl << "--test 1.1 (const vector)--" << std::endl;
	try
	{
		const std::vector<int> intVector = {7, 0, -7, 17, 107};
		auto searched = easyfind(intVector, -7);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
		searched = easyfind(intVector, -1);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something went wrong" << std::endl;
	}
	


	std::cout << std::endl << "--test 2 (deque)--" << std::endl;
	try
	{
		std::deque<int> intDeque = {99, 0, -1, 1, 101};
		auto searched = easyfind(intDeque, 1);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
		searched = easyfind(intDeque, -11111);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something went wrong" << std::endl;
	}

	std::cout << std::endl << "--test 2.2 (const deque)--" << std::endl;
	try
	{
		const std::deque<int> intDeque = {7, 0, -7, 17, 107};
		auto searched = easyfind(intDeque, -7);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
		searched = easyfind(intDeque, -1);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something went wrong" << std::endl;
	}

	std::cout << std::endl << "--test 3 (array)--" << std::endl;
	try
	{
		std::array<int, 5> intArray = {99, 0, -1, 1, 101};
		auto searched = easyfind(intArray, 1);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
		searched = easyfind(intArray, -11111);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something went wrong" << std::endl;
	}

	std::cout << std::endl << "--test 3.3 (const array)--" << std::endl;
	try
	{
		const std::array<int, 5> intArray = {7, 0, -7, 17, 107};
		auto searched = easyfind(intArray, -7);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
		searched = easyfind(intArray, -1);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something went wrong" << std::endl;
	}

	std::cout << std::endl << "--test 4 (list)--" << std::endl;
	try
	{
		std::list<int> intlist = {99, 0, -1, 1, 101};
		auto searched = easyfind(intlist, 1);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
		searched = easyfind(intlist, -11111);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something went wrong" << std::endl;
	}

	std::cout << std::endl << "--test 4.4 (const list)--" << std::endl;
	try
	{
		const std::list<int> intlist = {7, 0, -7, 17, 107};
		auto searched = easyfind(intlist, -7);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
		searched = easyfind(intlist, -1);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something went wrong" << std::endl;
	}

	std::cout << std::endl << "--test 5 (forward list)--" << std::endl;
	try
	{
		std::forward_list<int> intForwardList = {99, 0, -1, 1, 101};
		auto searched = easyfind(intForwardList, 1);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
		searched = easyfind(intForwardList, -11111);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something went wrong" << std::endl;
	}

	std::cout << std::endl << "--test 5.5 (const forward list)--" << std::endl;
	try
	{
		const std::forward_list<int> intForwardList = {7, 0, -7, 17, 107};
		auto searched = easyfind(intForwardList, -7);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
		searched = easyfind(intForwardList, -1);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something went wrong" << std::endl;
	}

	std::cout << std::endl << "--test 6 (empty vector)--" << std::endl;
	try
	{
		std::vector<int> intVector;
		auto searched = easyfind(intVector, 1);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
		searched = easyfind(intVector, -11111);
		std::cout << "My iterator search returned: " << *searched << std::endl; 
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something went wrong" << std::endl;
	}
}
