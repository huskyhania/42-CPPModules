/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:22:15 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/07/09 19:20:13 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>

template <class T>
typename T::iterator easyfind(T &sth, const int &toFind)
{
	//std::cout << "non const call" << std::endl;
	typename T::iterator it = std::find(sth.begin(), sth.end(), toFind);
	if (it == sth.end())
		throw std::runtime_error("Value not found in the container");
	return it;
}

//const version
template <class T>
typename T::const_iterator easyfind(const T &sth, const int &toFind)
{
	//std::cout << "const call" << std::endl;
	typename T::const_iterator cit = std::find(sth.begin(), sth.end(), toFind);
	if (cit == sth.end())
		throw std::runtime_error("Value not found in the container");
	return cit;
}
