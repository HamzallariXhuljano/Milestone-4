/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:31:52 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/27 17:26:56 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain() {std::cout<<"Default brain custructor"<<std::endl;}

Brain::Brain(std::string ideas[100])
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas[i];
	std::cout<<"Now the ideas is in your head"<<std::endl;
}
Brain::Brain(const Brain &obj)
{
	this->operator= (obj);
	std::cout<<"oh no, you copy my ideas"<<std::endl;
}
Brain& Brain::operator=(const Brain &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	}
	return *this;
}

Brain::~Brain() {std::cout<<"Destructor Brain called"<<std::endl;}
