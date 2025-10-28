/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:30:48 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/27 18:31:25 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) { std::cout<<"Mew mew i m a cat"<<std::endl;}

Cat::Cat(std::string type) : Animal(type), brain(new Brain())
{
	this->type = type;
	std::cout<<"This animal is cat????"<<std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	this->brain = new Brain(*obj.brain);//cosi cre una copia piu profonda (deep copy crea una nuova area di memoria e copia i contenuti) cosi ognuno ha un acesso indipendente
	this->operator= (obj);
	std::cout<<"Wow an other cat here incredible"<<std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
	if (this != &obj)
	{
		this->type = obj.type;
		if (this->brain)
			*(this->brain) = *(obj.brain);
		else
			this->brain = new Brain(*obj.brain);//deep copy del contenuto del cervello di obj
	}
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout<<"Sorry but the cat go to drink the milk to an other house :("<<std::endl;
}

void Cat::makeSound() const
{
	std::cout<<"Mew Mew cats don’t bark mew mew"<<std::endl;
}

void Cat::setCatIdea(int idx, std::string idea)
{
	this->brain->setIdea(idx, idea);
}

std::string Cat::getCatIdea(int idx)
{
	return this->brain->getIdea(idx);
}
