/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:36:20 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/08 18:57:28 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
	std::cout << "An animal is created" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "An animal of type " << type << " is created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj)
{
	this->operator= (obj);
}

AAnimal& AAnimal::operator=(const AAnimal &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "An animal is destroyed" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "Animals make strange sound..." << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}
