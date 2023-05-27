/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:22:39 by aoner             #+#    #+#             */
/*   Updated: 2023/05/27 07:35:20 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Binary_search algorithm search!
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
		std::vector<std::pair<std::string, std::string> > _vInput;
		std::vector<std::pair<std::string, double> > _vData;
        if (file_check(argv[1], file) == false)
		{
			return (EXIT_FAILURE);
		}
		if (fill_input(file, _vInput) == false)
		{
        	std::cerr << "Error: File is empty!" << std::endl;
			return(EXIT_FAILURE);
		}
		mark_invalid_input(_vInput);
		if (!file_check("data.csv", file))
		{
			return (EXIT_FAILURE);
		}
		fill_data_base(file, _vData);
		print_and_handle(_vInput, _vData);
	}
}
