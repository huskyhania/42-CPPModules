/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:51:46 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/07/15 17:52:19 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	{
		try
		{
			std::cout << "--school main--" << std::endl;
			MutantStack<int> mstack;
			mstack.push(5);
			mstack.push(17);
			std::cout << mstack.top() << std::endl;
			mstack.pop();
			std::cout << mstack.size() << std::endl;
			mstack.push(3);
			mstack.push(5);
			mstack.push(737);
			//[...]
			mstack.push(0);
			MutantStack<int>::iterator it = mstack.begin();
			MutantStack<int>::iterator ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
			std::cout << *it << std::endl;
			++it;
			}
			std::stack<int> s(mstack);
		}
		catch (...)
		{
			std::cout << "sth went wrong...";
		}
	}
	{
		try
		{
			std::cout << "--list test based on school test--" << std::endl;
			std::list<int> mstack;
			mstack.push_back(5);
			mstack.push_back(17);
			std::cout << mstack.back() << std::endl;
			mstack.pop_back();
			std::cout << mstack.size() << std::endl;
			mstack.push_back(3);
			mstack.push_back(5);
			mstack.push_back(737);
			//[...]
			mstack.push_back(0);
			auto it = mstack.begin();
			auto ite = mstack.end();
			++it;
			--it;
			while (it != ite)
			{
			std::cout << *it << std::endl;
			++it;
			}
		}
		catch (...)
		{
			std::cout << "sth went wrong...";
		}
	}
	{
		try{
		std::cout << "--test 3--" << std::endl;
		MutantStack<int> m1;
		m1.push(1);
		m1.push(2);
		m1.push(3);
		const MutantStack<int> cMutant = m1;
		for (MutantStack<int>::const_iterator it = cMutant.begin(); it != cMutant.end(); ++it)
			std::cout << *it << std::endl;
		}
		catch (...)
		{
			std::cout << "sth went wrong...";
		}
	}
	{
		try
		{
			std::cout << "--test 4--" << std::endl;
			MutantStack<int> mtest;
			std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
			for (int n : numbers)
				mtest.push(n);
			MutantStack<int>::iterator it = mtest.begin();
			while (it != mtest.end())
			{
				std::cout << *it;
				++it;
			}
			std::cout << std::endl;
			MutantStack<int>::iterator ite = mtest.end();
			while (ite != mtest.begin())
			{
				--ite;
				std::cout << *ite;
			}
			std::cout << std::endl;
		}
		catch (...)
		{
			std::cout << "sth went wrong...";
		}
	}
	{
		try
		{
			std::cout << "--test 5 (const)--" << std::endl;
			MutantStack<int> mtest;
			std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
			for (int n : numbers)
				mtest.push(n);
			const MutantStack<int> constTest(mtest);
			MutantStack<int>::const_iterator cit = constTest.begin();
			while (cit != constTest.end())
			{
				std::cout << *cit;
				++cit;
			}
			std::cout << std::endl;
			MutantStack<int>::const_iterator cite = constTest.end();
			while (cite != constTest.begin())
			{
				--cite;
				std::cout << *cite;
			}
			std::cout << std::endl;
		}
		catch (...)
		{
			std::cout << "sth went wrong...";
		}
	}
}
