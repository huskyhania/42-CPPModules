/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:13:38 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/06/07 21:19:47 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class myType>
myType &max(myType &a, myType &b)
{
	return a > b ? a : b;
}

template <class myType>
myType &min(myType &a, myType &b)
{
	return a < b ? a : b;
}

template <class myType>
void swap(myType &a, myType &b)
{
	myType temp;
	
	temp = a;
	a = b;
	b = temp;
}
