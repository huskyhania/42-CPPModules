/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:38:11 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/04/03 18:48:17 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

//same side test or half-plane test (using cross product)

Fixed	calculateSign(const Point& a, const Point& b, const Point& c)
{
	Fixed x_a = a.getX();
	Fixed y_a = a.getY();
	Fixed x_b = b.getX();
	Fixed y_b = b.getY();
	Fixed x_c = c.getX();
	Fixed y_c = c.getY();
	
	Fixed dx1 = x_a - x_c;
	Fixed dy1 = y_a - y_c;
	Fixed dx2 = x_b - x_c;
	Fixed dy2 = y_b - y_c;

	Fixed result = (dx1 * dy2) - (dx2 * dy1);
	return result;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = calculateSign(point, a, b);
	Fixed d2 = calculateSign(point, b, c);
	Fixed d3 = calculateSign(point, c, a);

	return (d1 > Fixed(0) && d2 > Fixed(0) && d3 > Fixed(0)) ||
		(d1 < Fixed(0) && d2 < Fixed(0) && d3 < Fixed(0));
}

void	printResult(Point testPoint, bool result)
{
	if (result)
		std::cout << testPoint << " point is inside the triangle" << std::endl;
	else
		std::cout << testPoint << " point is outside the triangle" << std::endl;
}

int main(void)
{
	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);
	Point toCheck(5, 5);
	std::cout << "Point a: " << a << std::endl;
	std::cout << "Point b: " << b << std::endl;
	std::cout << "Point c: " << c << std::endl;
	
	bool insideTriangle = bsp(a, b, c, toCheck);
	printResult(toCheck, insideTriangle);
	
	//border check
	Point toCheck2(10, 30);
	insideTriangle = bsp(a, b, c, toCheck2);
	printResult(toCheck2, insideTriangle);
	
	Point toCheck3(30, 30);
	insideTriangle = bsp(a, b, c, toCheck3);
	printResult(toCheck3, insideTriangle);
	
	Point toCheck4(9, 15);
	insideTriangle = bsp(a, b, c, toCheck4);
 	printResult(toCheck4, insideTriangle);

	Point toCheck5(10.1, 30.2);
	insideTriangle = bsp(a, b, c, toCheck5);
	printResult(toCheck5, insideTriangle);
	
	Point fa(0.5, 1.5);
	Point fb(10.5, 30.5);
	Point fc(20.5, 0.5);
	Point fCheck(0.5, 1.5);
	insideTriangle = bsp(fa, fb, fc, fCheck);
	printResult(fCheck, insideTriangle);
	
	Point nullA(0.0, 0.0);
	Point nullB(0.0, 0.0);
	Point nullC(0.0, 0.0);
	std::cout << "point a: " << nullA << " point b: " << nullB << " point c: " << nullC << std::endl;
	Point nullPoint(0.0, 0.0);
	insideTriangle = bsp(nullA, nullB, nullC, nullPoint);
	printResult(nullPoint, insideTriangle);
	return 0;
}
