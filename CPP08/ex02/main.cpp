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

int main(void)
{
	{
		try{
		std::cout << "--test 1--" << std::endl;
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
}
