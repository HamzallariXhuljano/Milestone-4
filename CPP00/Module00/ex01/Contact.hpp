/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:34:31 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/09 20:15:50 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	public:
	Contact (void);
	~Contact (void);
	void add(std::string name, std::string last_name, std::string nickname, std::string phonenumber,std::string darkest_secret);
	std::string getName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
	private:
		std::string name;
		std::string last_name;
		std::string nickname;
		std::string phonenumber;
		std::string darkest_secret;
};

#endif
