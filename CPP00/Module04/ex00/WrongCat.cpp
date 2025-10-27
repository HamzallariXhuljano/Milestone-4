/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:48:47 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/24 16:00:08 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include "Dog.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat") { std::cout<<"Mew mew i m a cat"<<std::endl;}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	this->type = type;
	std::cout<<"This animal is cat????"<<std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	this->operator= (obj);
	std::cout<<"Wow an other cat here incredible"<<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

WrongCat::~WrongCat() {std::cout<<"Sorry but the cat go to drink the milk to an other house :("<<std::endl;}

void WrongCat::makeSound() const
{
	std::cout<<"Mew Mew cats don’t bark mew mew"<<std::endl;
}
