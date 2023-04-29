/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:22:39 by aoner             #+#    #+#             */
/*   Updated: 2023/04/29 18:50:43 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file";
		exit(EXIT_FAILURE);
	}
	else
	{
		BitcoinExchange btc;
    	std::ifstream file;
        std::string line;
		file.open(argv[1]);
		if (file)
			btc.set_fileName(argv[1]);
    	else
		{
			std::cerr << "Error: could not open file";
			exit(EXIT_FAILURE);
		}
		std::vector<std::string> _v;
		while(std::getline(file, line))
		{
			_v.push_back(line);
		}
		file.close();
		btc.file_ctrl(_v);
	}
}