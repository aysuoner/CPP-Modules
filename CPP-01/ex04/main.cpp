/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:34:19 by aoner             #+#    #+#             */
/*   Updated: 2023/01/18 20:29:00 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	ReplaceStringInPlace(std::string& subject, const std::string& search, const std::string& replace) //bunu header kütüphanesinde nereye yazmalıyım?
{
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos)
	{
         subject.replace(pos, search.length(), replace);
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
		std::cout << "Cannot read File \n";
	}
	in_file.close();
	out_file.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return(0);
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
