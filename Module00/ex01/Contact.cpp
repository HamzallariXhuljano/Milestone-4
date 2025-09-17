/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:04:59 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/09 20:16:44 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::add(std::string name, std::string last_name, std::string nickname, std::string phonenumber,std::string darkest_secret)
{
	this->name = name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phonenumber = phonenumber;
	this->darkest_secret = darkest_secret;
	std::cout << this->name << std::endl;
}

std::string Contact::getName()
{
	return this->name;
}

std::string Contact::getLastName()
{
	return this->last_name;
}

std::string Contact::getNickName()
{
	return this->nickname;
}

std::string Contact::getDarkestSecret()
{
	return this->darkest_secret;
}

std::string Contact::getPhoneNumber()
{
	return this->phonenumber;
}
