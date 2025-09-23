/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:25:34 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/23 14:33:12 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie {

	private:
		std::string name;

	public:
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setName(std::string);
};

Zombie *zombieHorde(int N, std::string name);
# endif
