/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:57:20 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/28 23:49:19 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &initial)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = initial;
}

Fixed::Fixed(const int valueInt)
{
	std::cout << "Int constructor called" << std::endl;
	int result = valueInt * (1 << bits);//it could just be (value * 256)
	_value = result;
}

Fixed::Fixed(const float valueFl)
{
	std::cout << "Float constructor called" << std::endl;
	float temp = valueFl * (1 << bits);//this also could be (value * 256.0f)
	int rounded = roundf(temp);
	_value = rounded;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& initial)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &initial)
	{
		this->_value = initial.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return _value / (float)(1 << bits);
}

int	Fixed::toInt (void ) const
{
	return _value >> bits;
}

std::ostream &operator << (std::ostream &outstream, const Fixed &fixed)
{
	outstream << fixed.toFloat();
	return outstream;
}
