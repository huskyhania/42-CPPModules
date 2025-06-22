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

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>
#include <exception>

template <class T>
class Array
{
	private:
		size_t _size;
		T *_array;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &original);
		Array &operator=(const Array &original);
		T &operator[](unsigned int index);
		~Array();

		size_t size() const;
};

#include "Array.tpp"

#endif