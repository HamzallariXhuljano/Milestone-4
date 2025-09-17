/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:40:04 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/09 20:20:50 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook (void);
		~PhoneBook (void);
		void search(int index);
		void add_contact_phonebook(Contact &contact);
		bool print_phonebook();
	private:
		Contact contacts[8];
		int size;
};

#endif
