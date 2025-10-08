/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:36:20 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/08 18:54:51 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "An animal is created" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "An animal of type " << type << " is created" << std::endl;
}

Animal::Animal(const Animal &obj)
{
	this->operator= (obj);
}

Animal& Animal::operator=(const Animal &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "An animal is destroyed" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animals make strange sound..." << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
