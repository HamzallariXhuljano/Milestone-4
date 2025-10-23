/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:09:32 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/23 14:53:51 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->name = "no name";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout<<"Default costructor of ScavTrap called"<<std::endl;}

ScavTrap:: ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout<<"Costructor with name ScavTrap called"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	this->operator=(obj);
	std::cout<<"Copy costructor of ScavTrap called"<<std::endl;

}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {std::cout<<"Distructor ScavTrap called"<<std::endl;}

void ScavTrap::guardGate()
{
	std::cout<<"ScavTrap is now in Gate"<<std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints  < 1)
		std::cout<<"ScavTrap "<< this->name<< " don't have energy to attack :("<<std::endl;
	else if (this->hitPoints < 1)
		std::cout<<"Oh no ScavTrap "<<this->name<< " he cannot attack becauseeee is died:("<<std::endl;
	else
	{
		this->energyPoints--;
		std::cout<<"ScavTrap "<< this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!"<<std::endl;
	}
}
