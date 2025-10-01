/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:23:11 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/30 19:33:07 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->int_num = 0;
	// std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int int_param)
{
	// std::cout<<"Int constructor called"<<std::endl;
	this->int_num = int_param << bit_num;
}

Fixed::Fixed(const float float_parm)
{
	// std::cout<<"Float constructor called"<<std::endl;
	this->int_num = roundf(float_parm * (1 << bit_num));
}

Fixed::Fixed(const Fixed &obj)
{
	this->operator=(obj);
	// std::cout<<"Copy constructor called"<<std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	// std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &obj)
	{
		this->int_num = obj.int_num;
	}
	return *this;
}

Fixed::~Fixed()
{
	// std::cout<<"Destructor called"<<std::endl;
}
int Fixed::getRawBits(void) const
{
	// std::cout<<"getRawBits member function called"<<std::endl;
	return this->int_num;
}

void Fixed::setRawBits(int const raw)
{
	this->int_num = raw;
}

float Fixed::toFloat(void) const
{
	return (float)int_num / (1 << bit_num);
}

int Fixed::toInt(void) const
{
	return int_num >> bit_num;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return out;
}

bool Fixed::operator < (const Fixed &op) const
{
	return this->int_num < op.int_num;
}

bool Fixed::operator > (const Fixed &op) const
{
	return this->int_num > op.int_num;
}

bool Fixed::operator <= (const Fixed &op) const
{
	return this->int_num <= op.int_num;
}

bool Fixed::operator >= (const Fixed &op) const
{
	return this->int_num >= op.int_num;
}

bool Fixed::operator == (const Fixed &op) const
{
	return this->int_num == op.int_num;
}

bool Fixed::operator != (const Fixed &op) const
{
	return this->int_num != op.int_num;
}


Fixed Fixed::operator + (const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator - (const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator / (const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed Fixed::operator * (const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

//++a
Fixed& Fixed::operator ++ (void)
{
	this->int_num++;
	return *this;
}
//a++
Fixed Fixed::operator ++ (int)
{
	Fixed tmp = *this;
	this->int_num++;
	return tmp;
}

//--a
Fixed& Fixed::operator -- (void)
{
	this->int_num--;
	return *this;
}

//a--
Fixed Fixed::operator -- (int)
{
	Fixed tmp = *this;//si puo scrivere anche Fixed tmp(*this)
	this->int_num--;
	return *this;
}

Fixed& Fixed::min(Fixed &one, Fixed &two)
{
	if (one < two)
		return one;
	return two;
}

const Fixed& Fixed::min(const Fixed &one, const Fixed &two)
{
	if (one < two)
		return one;
	return two;
}

Fixed& Fixed::max(Fixed &one, Fixed &two)
{
	if (one > two)
		return one;
	return two;
}

const Fixed& Fixed::max(const Fixed &one, const Fixed &two)
{
	if (one > two)
		return one;
	return two;
}
