/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:35:29 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/29 22:00:39 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#define MAX_FIXED 8388607
#define MIN_FIXED -8388608 

class Fixed
{
	private:
		int _value;
		static const int bits = 8;
	public:
		Fixed(); 				//default constructor that initializes fixed-point number to 0
		Fixed(const Fixed &initial);		//copy constructor
		Fixed(const int valueInt);			//int constructor
		Fixed(const float valueFl);		//float constructor
		~Fixed();                               //destructor
		
		
		Fixed& operator=(const Fixed& initial);	//copy assignement operator oveload
		
		//comparison operators overload
		bool operator > (const Fixed &num) const;
		bool operator < (const Fixed &num) const;
		bool operator >= (const Fixed &num) const;
		bool operator <= (const Fixed &num) const;
		bool operator == (const Fixed &num) const;
		bool operator != (const Fixed &num) const;

		//arithmetic operators overload
		Fixed operator + (const Fixed &num) const;
		Fixed operator - (const Fixed &num) const;
		Fixed operator * (const Fixed &num) const;
		Fixed operator / (const Fixed &num) const;

		//increment/decrement operators overload
		Fixed& operator ++ ();
		Fixed& operator -- ();
		Fixed operator ++ (int);
		Fixed operator -- (int);

		int	getRawBits( void ) const;	// returns the raw value of the fixed-point value
		void	setRawBits( int const raw );
		
		float	toFloat( void ) const;
		int	toInt( void ) const;

		static Fixed		&min(Fixed &num1, Fixed &num2);
		static Fixed		&max(Fixed &num1, Fixed &num2);
		static const Fixed	&min(const Fixed &num1, const Fixed &num2);
		static const Fixed	&max(const Fixed &num1, const Fixed &num2); 

		static Fixed			checkOverflowUnderflow(float result);
};

std::ostream &operator << (std::ostream &outstream, const Fixed &fixed);

#endif
