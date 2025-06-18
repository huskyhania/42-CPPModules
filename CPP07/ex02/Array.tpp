# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Array.tpp                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 20:10:14 by hskrzypi          #+#    #+#              #
#    Updated: 2025/06/18 20:24:02 by hskrzypi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "Array.hpp"

template <class T>
Array<T>::Array()
{
	new Array();//creates an empty array, this should likely be a nullptr
}

template <class T>
Array<T>::Array(unsigned int n)
{
	//Creates an array of n elements initialized by default.
}

template <class T>
Array<T>::Array(const Array &original)
{
	//copy of the array
	//DEEP COPY!!!!!
}

template <class T>
Array<T> &Array<T>::operator=(const Array &original)
{

}

template <class T>
Array<T>::~Array()
{
	delete(_array);
}

template <class T>
size_t Array<T>::size()
{
	return _size;
}