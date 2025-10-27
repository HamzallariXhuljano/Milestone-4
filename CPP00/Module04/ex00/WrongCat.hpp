/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:41:11 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/24 15:58:20 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	protected:
		std::string type;
	public:
		WrongCat();
		WrongCat(std::string);
		WrongCat(const WrongCat&);
		WrongCat& operator=(const WrongCat&);
		~WrongCat();
		void makeSound() const;
};


# endif
