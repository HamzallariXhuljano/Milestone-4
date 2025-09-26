/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:32:36 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/26 14:54:46 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr<< "wrong arguments"<<std::endl;
		return 1;
	}
	size_t pos = 0;
	size_t found_pos = 0;
	std::ifstream inputfile(av[1]);
	std::string line;
	std::string inName = av[1];
	std::string outName = inName + ".replace";
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string res;
	std::string buff;

	if (inName.empty())
	{
		std::cerr<<"empty file name"<<std::endl;
		return 2;
	}
	if (s1.empty())
	{
		std::cerr<<"empty string 1"<<std::endl;
		return 3;
	}
	if(!inputfile.is_open())
	{
		std::cerr<<"the file dosen't exist"<<std::endl;
		inputfile.close();
		return 4;
	}
	std::ofstream outfile(outName.c_str());
	while (std::getline(inputfile, buff))
	{
		line += buff + "\n";
	}
	found_pos = line.find(s1, pos);
	while (found_pos != std::string::npos)
	{
		res += line.substr(pos, found_pos - pos);
		res += s2;
		pos = found_pos + s1.length();
		found_pos = line.find(s1, pos);
	}
	res += line.substr(pos);
	outfile << res;
	outfile.close();
	inputfile.close();
	return 0;
}
