/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:15:30 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/25 14:39:41 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {

	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanB(std::string);
		HumanB(std::string, Weapon &type);
		~HumanB();
		void attack(void);
		void setWeapon(Weapon&);
};

#endif
