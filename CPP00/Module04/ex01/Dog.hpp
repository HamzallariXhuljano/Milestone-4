/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:30:52 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/27 17:51:54 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(std::string);
		Dog(const Dog&);
		Dog& operator=(const Dog&);
		~Dog();
		void makeSound() const;
		void setDogIdea(int, std::string);
		std::string getDogIdea(int);
};

#endif

