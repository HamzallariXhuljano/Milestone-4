/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:31:43 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/17 16:38:29 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

void	check_input(std::string &s, std::string msg, std::string msg1, int i)
{
	std::cout<<msg<<std::endl;
	getline(std::cin, s);

	if (i == 0)
	{
		while(s.empty())
		{
			std::cerr<<msg1<<std::endl;
			getline(std::cin, s);
		}
	}
	else if (i == 1)
	{
		if (!s.empty() && !is_digit(s))
		{
			while (!is_digit(s))
			{
				std::cout<<"The phone number must have only digits"<<std::endl;
				getline(std::cin, s);
			}
		}
		while(s.empty())
		{
			std::cerr<<msg1<<std::endl;
			getline(std::cin, s);
			while (!is_digit(s))
			{
				std::cout<<"The phone number must have only digits"<<std::endl;
				getline(std::cin, s);
			}
		}
	}
}

bool	is_digit(std::string s)
{
	if(s.find_first_not_of("0123456789") != std::string::npos)//npos fine della stringa (find_first_not of ritorna indice stringa)
		return (0);
	return (1);
}

std::string	max_len(std::string s)
{
	if (s.size() >= 10)
	{
		std::string string = s.substr(0,9) + ".";
		return string;
	}
	return s;
}
