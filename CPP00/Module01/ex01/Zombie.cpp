/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:32:01 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/23 14:47:30 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{

}

Zombie::~Zombie()
{
	std::cout<< "Zombie finally dead"<< std::endl;
}

void Zombie::announce()
{
	std::cout<<this->name<<" : BraiiiiiiinnnzzzZ..."<<std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
