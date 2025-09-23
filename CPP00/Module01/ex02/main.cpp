/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:54:32 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/23 15:05:11 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str= "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string& strREF = str;

	std::cout<<"Memory address of str variable: "<<&str<<std::endl;
	std::cout<<"Memory addrees held by strPTR: "<<strPTR<<std::endl;
	std::cout<<"Memory address held by strREF: "<<&strREF<<std::endl;
	std::cout<<"Value of the str variable: "<<str<<std::endl;
	std::cout<<"Value pointed to by stringPTR: "<<*strPTR<<std::endl;
	std::cout<<"Value pointed to by stringREF: "<<strREF<<std::endl;
}
