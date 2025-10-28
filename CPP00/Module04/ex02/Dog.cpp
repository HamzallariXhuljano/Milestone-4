/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:41:38 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/28 14:36:23 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), brain(new Brain){  std::cout << "A new dog is born" << std::endl; }

Dog::Dog(std::string type) : AAnimal(type), brain(new Brain())
{
	this->type = type;
	std::cout << "What type of animal is this ???" << std::endl;
}

Dog::Dog(const Dog &obj) : AAnimal(obj)
{
	this->brain = new Brain(*obj.brain);
	this->operator= (obj);
}

Dog& Dog::operator=(const Dog &obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
		delete this->brain;
		this->brain = new Brain(*obj.brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "The dog goes to catch a cat" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bau bau bau! What did you mean with bau?" << std::endl;
}

void Dog::setDogIdea(int idx, std::string idea)
{
	this->brain->setIdea(idx, idea);
}

std::string Dog::getDogIdea(int idx)
{
	return this->brain->getIdea(idx);
}
