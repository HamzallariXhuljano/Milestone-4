/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:23:09 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/29 18:54:52 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	int_num;
		static const int bit_num = 8;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed& obj);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};
# endif
