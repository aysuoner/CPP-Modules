/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:22:39 by aoner             #+#    #+#             */
/*   Updated: 2023/05/01 21:37:10 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//try-catch kullanmalı mıyım?
//başında date | value kullanmak ve kontrol etmek gerekir mi?
//her error mesajı farklı olmak zorunda mı?
//input.txt boşsa error bastırmalı mıyım?
//input.txt'ye güncel bir tarih verirsek ne olmalı?

int main(int argc, char **argv)
{	
	if (argc != 2)
	{
		std::cerr << "Error: Arguments too few" << std::endl;
		return(EXIT_FAILURE);
	}
	else
	{
    	std::ifstream file;
		std::vector<std::pair<std::string, std::string> > _v;
		std::vector<std::pair<std::string, double> > _vData;
        if (file_check(argv[1], file) == false)
		{
			return (EXIT_FAILURE);
		}
		if (fill_input(file, _v) == false)
		{
        	std::cerr << "Error: File is empty!" << std::endl;
			return(EXIT_FAILURE);
		}
		mark_invalid_input(_v);
		if (!file_check("data.csv", file))
		{
			return (EXIT_FAILURE);
		}
		fill_data_base(file, _vData);
		print_and_handle(_v, _vData);
	}
}

/* 		
		std::cout << std::endl;
		std::cout << std::endl;
		for (std::vector<std::pair<std::string, std::string> >::const_iterator it = _v.begin(); it != _v.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		for (std::vector<std::pair<std::string, double> >::const_iterator it = _vData.begin(); it != _vData.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << std::endl;
		} */