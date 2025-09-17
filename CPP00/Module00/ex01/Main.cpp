/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:27:25 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/17 16:42:05 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Utils.hpp"

int main(){
	std::string insert_name;
	std::string insert_last_name;
	std::string insert_nickname;
	std::string insert_phonenumber;
	std::string insert_darkest_secret;
	std::string command;
	Contact contact;
	PhoneBook phoneBook;
	while (1)
	{
		std::cout<<"Insert one of these command: ADD, SEARCH and EXIT" << std::endl;
		if(!getline(std::cin,command))
			break;
		if (command == "ADD")
		{
			check_input(insert_name, "Insert the name to add", "You have to insert the name to add", 0);
			check_input(insert_last_name, "Insert the last name to add", "You have to insert the last name to add", 0);
			check_input(insert_nickname, "Insert the nickname to add", "You have to insert the nickname to add", 0);
			check_input(insert_phonenumber, "Insert the phone number to add", "You have to insert the phone number to add", 1);
			check_input(insert_darkest_secret, "Insert the darkest secret to add", "You have to insert the darkest secret to add", 0);
			contact.add(insert_name, insert_last_name, insert_nickname, insert_phonenumber, insert_darkest_secret);
			phoneBook.add_contact_phonebook(contact);
			std::cout<<"ADD"<<std::endl;
		}
		else if (command == "SEARCH")
		{
			if (!phoneBook.print_phonebook())
				continue;
			std::string input_index;
			int index;
			getline(std::cin, input_index);
			std::stringstream tmp (input_index);
			tmp >> index;
			if (tmp.fail())
			{
				std::cerr<<"not integer";
				break;
			}
			phoneBook.search(index);
			std::cout<<"SEARCH"<<std::endl;
		}
		else if (command == "EXIT")
		{
			std::cout<<"EXIT"<<std::endl;
			break;
		}
	}
}
