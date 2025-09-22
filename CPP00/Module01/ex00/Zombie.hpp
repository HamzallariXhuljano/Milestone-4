/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:45:44 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/22 17:22:28 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {



	private:
		std::string name;

	public:
		Zombie (std::string name);
		~Zombie ();
		void announce(void);
		std::string getName();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
#endif
