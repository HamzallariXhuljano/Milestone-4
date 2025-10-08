/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:28:10 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/08 18:18:33 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include "AAnimal.hpp"

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(std::string[100]);
		Brain(const Brain&);
		Brain& operator=(const Brain&);
		~Brain();
};

#endif
