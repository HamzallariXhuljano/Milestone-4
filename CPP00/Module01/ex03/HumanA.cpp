/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:15:39 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/25 14:14:15 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &other):weapon(other)
{
	this->name = name;
}


HumanA::~HumanA()
{

}


void HumanA::attack(void)
{
	std::cout<<this->name<<" attacks with their "<<this->weapon.getType()<<std::endl;
}
