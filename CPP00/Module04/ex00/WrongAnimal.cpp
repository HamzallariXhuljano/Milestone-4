/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:47:31 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/24 15:48:34 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Animal")
{
	std::cout << "An animal is created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "An animal of type " << type << " is created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	this->operator= (obj);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "An animal is destroyed" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Animals make strange sound..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
