/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:34:27 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/23 14:49:37 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++ )
	{
		zombieHorde[i].setName(name);
		zombieHorde[i].announce();
	}
	
	return (zombieHorde);
}
