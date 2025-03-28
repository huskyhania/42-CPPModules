/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:40:45 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/28 20:56:46 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _value;
		static const int bits = 8;
	public:
		Fixed(); 				//default constructor that initializes fixed-point number to 0
		Fixed(const Fixed &initial);		//copy constructor
		Fixed(const int value);
		Fixed(const float flValue);
		Fixed& operator=(const Fixed& initial);	//copy assignement operator oveload
		~Fixed();				//destructor
		
		int	getRawBits( void ) const;	// returns the raw value of the fixed-point value
		void	setRawBits( int const raw );
		
		float	toFloat( void ) const;
		int	toInt( void ) const;
};

std::ostream &operator << (std::ostream &outstream, const Fixed &fixed);

#endif
