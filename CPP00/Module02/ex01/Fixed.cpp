/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:23:11 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/29 18:57:43 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->int_num = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	this->operator=(obj);
	std::cout<<"Copy constructor called"<<std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &obj)
	{
		this->int_num = obj.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}
int Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return this->int_num;
}

void Fixed::setRawBits(int const raw)
{
	this->int_num = raw;
}

float Fixed::toFloat(void) const
{

}

int Fixed::toInt(void) const
{

}
