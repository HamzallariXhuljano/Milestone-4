/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:10:10 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/01 17:52:07 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float a, const float b) : x(a) , y(b){}

Point::Point(const Point &obj) : x(obj.x), y(obj.y)
{
	
}
Point& Point::operator=(const Point &obj)
{
	//cannot overload the variable because they are const//
	(void)obj;
	return *this;
}

float Point::getX() const
{
	return this->x.toFloat();
}

float Point::getY() const
{
	return this->y.toFloat();
}

Point::~Point()
{

}
