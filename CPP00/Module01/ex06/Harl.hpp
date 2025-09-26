/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:15:25 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/26 17:15:27 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
# include <iomanip>
# include <cctype>

class Harl{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void (Harl::*Complains[4])(void);
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

# endif
