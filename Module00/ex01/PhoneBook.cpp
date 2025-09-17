/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:30:11 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/09 20:22:11 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include "Utils.hpp"

PhoneBook::PhoneBook() {
	this->size = 0;
}
PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact_phonebook(Contact &contact)
{
	if (this->size < 8)
	{
		this->contacts[size] = contact;
		size++;
	}
	else
	{
		for (int i = 0; i < 7; i++)
			this->contacts[i] = this->contacts[i+1];
		this->contacts[size-1] = contact;
	}
}

bool PhoneBook::print_phonebook()
{
	if (this->size > 0)
	{
		std::cout<<std::right<<std::setw(10)<<"index"<<"|"
				<<std::setw(10)<<"name"<<"|"
				<<std::setw(10)<<"last name"<<"|"
				<<std::setw(10)<<"nickname"<<"|"<<std::endl;
		for (int i = 0; i < this->size; i++)
			std::cout<<std::right<<std::setw(10)<<i+1<<"|"
					<<std::setw(10)<<max_len(this->contacts[i].getName())<<"|"
					<<std::setw(10)<<max_len(this->contacts[i].getLastName())<<"|"
					<<std::setw(10)<<max_len(this->contacts[i].getNickName())<<"|"<<std::endl;
		std::cout<<"Choose the index to find"<<std::endl;
		return 1;
	}
	else
		std::cout<<"EMPTY PHONEBOOK"<<std::endl;
	return 0;
}

void PhoneBook::search(int index)
{
	int find = 0;

	for (int i = 0; i <= this->size; i++)
	{
		if (i + 1 == index)
		{
			std::cout<<"index: "<<index<<std::endl
					<<"name: "<<this->contacts[i].getName()<<std::endl
					<<"last name: "<<this->contacts[i].getLastName()<<std::endl
					<<"nickname: "<<contacts[i].getNickName()<<std::endl
					<<"phone number: "<<this->contacts[i].getPhoneNumber()<<std::endl
					<<"darkest secret: "<<this->contacts[i].getDarkestSecret()<<std::endl;
			find = 1;
		}
	}
	if (find == 0)
		std::cout<<"Wrong index"<<std::endl;
}

