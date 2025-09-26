/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:16:06 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/26 17:56:19 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout<<"Wrong arguments"<<std::endl;
		return 1;
	}
	Harl harl;
	std::string level = av[1];
	harl.complain(level);
	return (0);
}
