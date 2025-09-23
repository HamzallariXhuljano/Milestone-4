/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:23:41 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/23 14:52:19 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	std::string hordeName;
	std::string string_n;
	int n;

	std::cout<<"Choose the horde name"<<std::endl;
	getline(std::cin, hordeName);
	std::cout<<"Choose the numbers of zombie you want"<<std::endl;
	getline(std::cin, string_n);
	std::stringstream ss(string_n);
	ss >> n;
	horde = zombieHorde(n, hordeName);

	delete[] horde;//decstruttor for arry of horde
 }
