/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:38:35 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/28 14:36:55 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	int size = 10;
	AAnimal *animals[size];
	std::cout << "====== Testing type Animol ======" << std::endl;
	for (int i = 0; i<size; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "====== Testing make sound  ======" << std::endl;

	for (int i = 0; i < size; i++)
	{
		animals[i]->makeSound();
	}
	std::cout << "====== Testing Brain Animol ======" << std::endl;
	Cat *c = dynamic_cast <Cat*>(animals[1]);
	if (c)
	{
		c->setCatIdea(1, "popopopopop");
	}
	Cat copyC = *c;
	std::cout<<"Original cat idea "<<c->getCatIdea(1);
	std::cout<<"Copy cat idea "<< copyC.getCatIdea(1)<<std::endl;
	std::cout << "====== Testing distructor Animol ======" << std::endl;

	for (int i = 0; i < size; i++)
		delete animals[i];
	return 0;
}
