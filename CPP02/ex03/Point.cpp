/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:25:00 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/30 20:28:55 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{
	//std::cout << "default constructor " << std::endl;
}

Point::Point(const float a, const float b) : x(Fixed(a)), y(Fixed(b))
{
	//std::cout << "parameter constructor " << std::endl;
}

Point::Point(const Point &original) : x(original.x), y(original.y)
{
	//std::cout << "copy constructor " << std::endl;
}

Point::~Point() {
	//std::cout << "destructor " << std::endl;
}

//new because of const - need to investigate further
Point	&Point::operator=(const Point &original)
{
	std::cout << "assignement operator message " << std::endl;
	if (this != &original)
	{
		Point *another = new Point(original);
		this->~Point();
		return *another;
	}
	return *this;
}

//bool	bsp(Point const a, Point const b, Point const c, Point const point)
const Fixed	Point::getX() const {return x;}
const Fixed	Point::getY() const {return y;}

std::ostream& operator<<(std::ostream &outstream, const Point &pt)
{
	outstream << pt.getX() << "," << pt.getY();
	return outstream;
}
