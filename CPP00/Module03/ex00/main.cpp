/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:20:24 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/01 19:41:42 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("Chamber");

	clapTrap.attack("Enemy");
	// clapTrap.attack("Enemy");
	// clapTrap.attack("Enemy");
	// clapTrap.attack("Enemy");
	// clapTrap.attack("Enemy");
	// clapTrap.attack("Enemy");
	// clapTrap.attack("Enemy");
	// clapTrap.attack("Enemy");
	// clapTrap.attack("Enemy");
	// clapTrap.attack("Enemy");
	// clapTrap.attack("Enemy");

	clapTrap.takeDamage(2);
	clapTrap.beRepaired(2);
	clapTrap.takeDamage(10);
	clapTrap.attack("Other Enemy");
	clapTrap.beRepaired(2);
}
