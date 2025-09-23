/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:43:19 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/23 12:50:03 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*zombie;

	zombie = newZombie("FOO");
	zombie->announce();
	delete zombie;
	randomChump("BrainzHunter");
}
