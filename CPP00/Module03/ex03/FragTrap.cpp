/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:47:49 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/02 21:06:36 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){std::cout<<"This costructor is the default costructor FragTrap not ScravTrap :)"<<std::endl;}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout<<"This costructor is the name costructor FragTrap not ScravTrap :)"<<std::endl;
}
FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	this->operator=(obj);
	std::cout<<"This costructor is the copy costructor FragTrap not ScravTrap :)"<<std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->attackDamage = obj.attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {std::cout<<"This destructir is the  destructor FragTrap not ScravTrap :)"<<std::endl;}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High 5 my Gs you did it"<< std::endl;
}
