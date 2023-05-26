/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:22:39 by aoner             #+#    #+#             */
/*   Updated: 2023/05/26 12:41:45 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*std::pair ise, içinde iki farklı veri tipi taşıyan bir yapıdır.
Bu yapı, her bir öğenin farklı bir veri tipinde olması gerektiğinde kullanılır.
Bu örnekte, std::pair'ın her bir öğesi, std::string veri tipinden bir anahtar (key)
ve bir değer (value) içermektedir.*/

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

//başında date | value kullanmak ve kontrol etmek gerekir mi?
	//Each line in this file must use the following format: "date | value". yazıyor pdfte yani gerekli değil??
//getline, make_pair, find_same_data_indx;

/* 2011-04-17 | 1
2011-04-14 | 1
2010-08-20 | 1.12
2009-08-03 | 1
2011-09-03 | 1
2011-08-03 | 1
2009-01-01 | 1
2009-03-01 |     1
2009-03-01 | 1       
2009-01-02 | 1
2009-01-05 | 1
sdsffdssd |  
asdadfsd 
 | 
2008_01_01 | 4
           | 
eeeeeeeeee |
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -3
2001-42-42
2012-01-11 | 1
2012-01-11 | 1001
2023-04-29 | 1
 */
