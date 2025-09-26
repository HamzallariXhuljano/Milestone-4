/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:15:36 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/25 17:34:11 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name)
{
	this->weapon = NULL;
	this->name = name;
}

// HumanB::HumanB(std::string name, Weapon &weapon)
// {
// 	this->weapon = &weapon;
// 	this->name = name;
// }

HumanB::~HumanB()
{

}

void HumanB::attack(void)
{
	if (weapon == NULL)
		return ;
	std::cout<<this->name<<" attacks with their "
				<<weapon->getType()<<std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
