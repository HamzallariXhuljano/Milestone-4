/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:24:59 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/06 17:22:52 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {std::cout << "Default Costructor DiamondTrap"<<std::endl;}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout<<"Name costructor DiamondTrap called :)"<<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj){
	this->operator= (obj);
	std::cout<<"Copy Custractor DiamondTrap called"<<std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &obj)
{
	if(this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(){std::cout<<"Distructor of DiamondTrap called"<<std::endl;}

void DiamondTrap::whoAmI()
{
	std::cout<<"DiamondTrap name: "<<this->name<<" ClapTrap name: "<<ClapTrap::name<<std::endl;
}
