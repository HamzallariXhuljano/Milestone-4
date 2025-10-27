/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:39:09 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/24 15:45:33 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class WrongAnimal
{

	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(std::string);
		WrongAnimal(const WrongAnimal&);
		WrongAnimal& operator=(const WrongAnimal&);
		~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
};


# endif
