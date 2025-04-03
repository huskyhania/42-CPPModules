/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:23:40 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/28 18:12:47 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;
	public:
		Fixed(); 				//default constructor that initializes fixed-point number to 0
		Fixed(const Fixed &initial);		//copy constructor
		Fixed& operator=(const Fixed& initial);	//copy assignement operator oveload
		~Fixed();				//destructor
		
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
