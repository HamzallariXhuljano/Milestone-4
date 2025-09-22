/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:51:03 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/22 17:15:56 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{

}

std::string Zombie::getName()
{
	return this->name;
}

void Zombie::announce()
{
	std::cout<<this->name<<": BraiiiiiiinnnzzzZ...";
}
