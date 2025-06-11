/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:07:47 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/06/08 14:22:35 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <class A>
void iter(A *array, size_t length, void(*func)(A &))
{
	for (size_t i = 0; i < length; i++)
		(func)(array[i]);
}

template <class A>
void iter(A *array, size_t length, void(*func)(const A &))
{
	for (size_t i = 0; i < length; i++)
		(func)(array[i]);
}