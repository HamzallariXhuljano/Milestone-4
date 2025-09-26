/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:15:35 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/26 18:00:49 by xhamzall         ###   ########.fr       */
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
	std::cout<<"[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}

void Harl::info( void )
{
	std::cout<<"[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::warning( void )
{
	std::cout<<"[WARNING]\nI think I deserve to have some extra bacon for free. I ve been coming for years, whereas you started working here just last month."<<std::endl;
}
void Harl::error( void )
{
	std::cout<<"[ERROR]\nThis is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain( std::string level)
{
	std::string input[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	for (; i < 4; i++)
	{
		if (input[i] == level)
			break;
	}
	switch(i)
	{
		case 0:
			(this->*Complains[0])();
			std::cout<<std::endl;
		case 1:
			(this->*Complains[1])();
			std::cout<<std::endl;
		case 2:
			(this->*Complains[2])();
			std::cout<<std::endl;
		case 3:
			(this->*Complains[3])();
			std::cout<<std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"<< std::endl;
	}

}
