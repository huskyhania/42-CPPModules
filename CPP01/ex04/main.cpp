/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:18:30 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/03/25 17:57:25 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

void search_and_replace(std::ifstream &inFile, std::string &s1, std::string &s2, std::ofstream &outFile)
{
	std::string line;
	while (std::getline(inFile, line, '\0'))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outFile << line << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		std::cerr << "Input 3 parametes: filename, s1, s2" << std::endl;
	else
	{
		std::string name = argv[1];
		std::string searched = argv[2];
		std::string replace = argv[3];
		if (searched.length() == 0)
		{
			std::cout << "Nothing to replace" << std::endl;
			return 1;
		}
		std::ifstream inFile;
		inFile.open(name);
		if (inFile.fail())
		{
			std::cout << "Error opening file" << std::endl;
			return 1;
		}
		std::ofstream outFile;
		outFile.open((name + ".replace"));
		if (outFile.fail())
		{
			std::cout << "Error creating outfile" << std::endl;
			inFile.close();
			return 1;
		}
		search_and_replace(inFile, searched, replace, outFile);
		inFile.close();
		outFile.close();
	}
	return 0;
}
