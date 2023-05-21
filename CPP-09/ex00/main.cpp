/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:22:39 by aoner             #+#    #+#             */
/*   Updated: 2023/05/21 17:56:57 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//try-catch kullanmalı mıyım?
//test 2008-01-01 | 4
//test 2008_01_01 | 4
//           | 
//eeeeeeeeee | 
//2009-01-01 | 1//datada olmayan veri hata vermeli
//2009-01-02 | 1//ilk data dogru vermeli
//2009-03-01 | 1 //calismali
//2009-03-01 |     1//bad input olmali
//2009-03-01 | 1       //bad input olmali
//başında date | value kullanmak ve kontrol etmek gerekir mi?
	//Each line in this file must use the following format: "date | value". yazıyor pdfte yani gerekli değil??
//her error mesajı farklı olmak zorunda mı?
//input.txt boşsa error bastırmalı mıyım?
//input.txt'ye güncel bir tarih verirsek ne olmalı?

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