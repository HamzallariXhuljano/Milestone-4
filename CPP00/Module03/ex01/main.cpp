/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:20:24 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/02 19:32:27 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap thilina("Chamber");

 	thilina.attack("Enemy");
	// thilina.attack("Enemy");
	// thilina.attack("Enemy");
	// thilina.attack("Enemy");
	// thilina.attack("Enemy");
	// thilina.attack("Enemy");
	// thilina.attack("Enemy");
	// thilina.attack("Enemy");
	// thilina.attack("Enemy");
	// thilina.attack("Enemy");
	// thilina.attack("Enemy");

	thilina.takeDamage(2);
	thilina.beRepaired(2);
	thilina.takeDamage(10);
	thilina.attack("Other Enemy");
	thilina.beRepaired(2);
	thilina.guardGate();
}
