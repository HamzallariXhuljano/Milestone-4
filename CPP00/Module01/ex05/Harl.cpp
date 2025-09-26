/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:26:29 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/26 16:53:37 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	Complains[0] = &Harl::debug;
	Complains[1] = &Harl::info;
	Complains[2] = &Harl::warning;
	Complains[3] = &Harl::error;
}
Harl::~Harl()
{

}
void Harl::debug( void )
{
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}

void Harl::info( void )
{
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::warning( void )
{
	std::cout<<"I think I deserve to have some extra bacon for free. I ve been coming for years, whereas you started working here just last month."<<std::endl;
}
void Harl::error( void )
{
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain( std::string level )
{
	std::string input[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
	{
		if (level == input[i])
		{
			(this->*Complains[i])();
			return ;
		}
	}
	std::cout<<"Wrong input"<<std::endl;
}
