/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:26:39 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/01 19:31:27 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() { std::cout<<"Default costructor called"<<std::endl;}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout<<"Costructor with name called"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	this->operator = (obj);
	std::cout<<"Copy costructor called"<<std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
	if (this != &obj)
	{
		this->attackDamage = obj.attackDamage;
		this->energyPoints = obj.energyPoints;
		this->hitPoints = obj.energyPoints;
		this->name = obj.name;
	}
	return *this;
}

ClapTrap::~ClapTrap() {std::cout<<"Destructor called"<<std::endl;}

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints  < 1)
		std::cout<<"ClpaTrap "<< this->name<< " don't have energy to attack :("<<std::endl;
	else if (this->hitPoints < 1)
		std::cout<<"Oh no ClpaTrap "<<this->name<< " is died:("<<std::endl;
	else
	{
		this->energyPoints--;
		std::cout<<"ClapTrap "<< this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!"<<std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{

	if (hitPoints <= amount)
	{
		this->hitPoints -= amount;
		std::cout<<"opsss your ClapTrap "<<this->name <<" died. Unlucky!"<<std::endl;
	}
	else
	{
		this->hitPoints -= amount;
		std::cout<< "Oh no you got -" << amount << " damage now you have " << this->hitPoints << " HitPoints, don't die!"<<std::endl;
	}

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints < 1)
		std::cout<<"ClpaTrap "<< this->name <<" don't have energy to reapaired himself"<<std::endl;
	else if (this->hitPoints < 1)
		std::cout<<"Opsss your ClapTrap "<<this->name <<" died. He cannot heal himself!"<<std::endl;
	else
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout<<"ClapTrap "<< this->name <<" repaired himself, +"<< amount<< " HitPoints now your Chamber got "<<this->hitPoints<<" HitPoints :)"<<std::endl;
	}
}
