/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:41:11 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/26 16:53:24 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;
	std::string level;

	while (1)
	{
		std::cout<<"Write one of this livel: debug, info, warning or error. Write exit to close"<<std::endl;
		if(!std::getline(std::cin, level))
			break;
		if (level == "exit")
			break;
		harl.complain(level);
	}
	return (0);
}
