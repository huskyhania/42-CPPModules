/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:31:14 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/30 18:03:16 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class	Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float a, const float b);
		Point(const Point &original);//copy constructor
		~Point();
		Point &operator=(const Point &original);
		const Fixed     getX() const;
		const Fixed     getY() const;
};

//bool bsp(Point const a, Point const b, Point const c, Point const point);

std::ostream& operator<<(std::ostream &outstream, const Point &pt);

#endif
