/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:38:35 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/08 18:58:22 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	int size = 10;
	const AAnimal *animals[size];

	for (int i = 0; i<size; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout<<"============================================================================="<<std::endl;
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();
	std::cout<<"============================================================================="<<std::endl;
	for (int i = 0; i < size; i++)
		delete animals[i];
	return 0;
}
