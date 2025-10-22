/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:09:36 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/22 17:23:33 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float area(Point const a, Point const b, Point const c)
{
	return std::abs((a.getX()*(b.getY()-c.getY())) + b.getX()*(c.getY()-a.getY()) + c.getX()*(a.getY()-b.getY()))/2.0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float areaPAC = area(a, point, c);
	std::cout<<"areaPAC "<<areaPAC<<std::endl;
	float areaPBC = area(point, b, c);
	std::cout<<"areaPBC "<<areaPBC<<std::endl;
	float areaPAB = area(a, b, point);
	std::cout<<"areaPAB "<<areaPAB<<std::endl;
	float areaABC = area(a, b, c);
	std::cout<<"areaABC "<<areaABC<<std::endl;
	if (areaPAB == 0 || areaPBC == 0 || areaPAC == 0)
		return false;
	if (areaABC == (areaPAC + areaPBC + areaPAB))
		return true;
	return false;
}
