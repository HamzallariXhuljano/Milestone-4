/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:41:38 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/06 19:50:47 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){  std::cout << "A new dog is born" << std::endl; }

Dog::Dog(std::string type) : Animal(type)
{
	this->type = type;
	std::cout << "What type of animal is this ???" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	*this = obj;
}

Dog& Dog::operator=(const Dog &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

Dog::~Dog() { std::cout << "The dog goes to catch a cat" << std::endl; }

void Dog::makeSound() const
{
	std::cout << "Bau bau bau! What did you mean with bau?" << std::endl;
}


