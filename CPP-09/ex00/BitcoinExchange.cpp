/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:22:12 by aoner             #+#    #+#             */
/*   Updated: 2023/04/29 19:47:02 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::set_fileName(std::string argv)
{
	this->_fileName = argv;
}

void	BitcoinExchange::file_ctrl(std::vector<std::string> &_v)
{
	std::string sub_str;
	std::string str;
	if (!_v.size())
		std::cerr << "Error: file is empty!";
	for (std::vector<std::string>::iterator it = _v.begin(); it != _v.end(); ++it) 
	{
		str = *it;
		size_t found = str.find(" | ");
	    if (found != std::string::npos)
		{
			sub_str = str.substr(0, found);
            std::cout << "sub: " << sub_str << std::endl;
			//Burada kaldım. şimdi bu tarihi kontrol etmem gerek.
        }
	}

}
