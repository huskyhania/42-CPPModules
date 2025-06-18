/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:04:18 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/06/18 19:04:37 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

template <class T>
class Array
{
	private:
		T *_array;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &original);
		Array &operator=(const Array &original);
		~Array();

		size_t size();
};
