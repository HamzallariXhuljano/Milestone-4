/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:23:10 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/22 17:23:47 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 30.0f);
	Point c(20.0f, 0.0f);
	Point p(0.0f, 0.0f);

	std::cout<< "punto b = "<<b.getX()<< b.getY()<<std::endl;
	if (bsp(a, b, c, p) == true)
		std::cout<<"The point is inside"<<std::endl;
	else
		std::cout<<"The point isn't inside"<<std::endl;
	return 0;
}
