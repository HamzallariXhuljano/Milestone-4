/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:48:27 by xhamzall          #+#    #+#             */
/*   Updated: 2025/10/02 21:00:23 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
	FragTrap();
	FragTrap(std::string);
	FragTrap(const FragTrap&);
	FragTrap& operator=(const FragTrap&);
	~FragTrap();
	void highFivesGuys(void);

};
