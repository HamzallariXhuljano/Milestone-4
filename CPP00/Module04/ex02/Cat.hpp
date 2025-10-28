/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:28:42 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/28 14:35:12 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(std::string);
		Cat(const Cat&);
		Cat& operator=(const Cat&);
		~Cat();
		void makeSound() const;
		void setCatIdea(int, std::string);
		std::string getCatIdea(int);
};


# endif
