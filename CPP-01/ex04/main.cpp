/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:34:19 by aoner             #+#    #+#             */
/*   Updated: 2023/01/19 11:27:34 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	ReplaceStringInPlace(std::string& line, const std::string& search,
								const std::string& replace)
{
    size_t pos = 0;
    while ((pos = line.find(search, pos)) != std::string::npos)
	{
         line.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}

void	create_and_copy(replace *replace_o, std::string argv1) //bunu header kütüphanesinde nereye yazmalıyım?
{
	std::string line;
	std::ifstream in_file(argv1);
	std::ofstream out_file(replace_o->getfilename());
	if (in_file && out_file)
	{
		while (getline(in_file, line))
		{
			ReplaceStringInPlace(line, replace_o->gets1(), replace_o->gets2());
			out_file << line << "\n";
		}
		std::cout << "Copy Finished \n";
	}
	else
	{
		std::cerr << "Cannot read File \n";
	}
	in_file.close();
	out_file.close();
}
//replace yasaklı fonksiyonmuş KALDIR!!!!!!
int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "You must enter three arguments!" << std::endl;
		return(EXIT_FAILURE);
	}
	else
	{
		replace replace_o = replace(argv[1], argv[2], argv[3]);
		replace_o.setfilename(argv[1]);
		create_and_copy(&replace_o, argv[1]);
		replace_o.sets1(argv[2]);
		replace_o.sets2(argv[3]);
		return 0;
	}
}
