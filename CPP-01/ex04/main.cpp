/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:34:19 by aoner             #+#    #+#             */
/*   Updated: 2023/01/17 18:15:40 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
		return(0);
	else
	{
		replace replace_o = replace(argv[1], argv[2], argv[3]);
		replace_o.setfilename(argv[1]);
		replace_o.sets1(argv[2]);
		replace_o.sets2(argv[3]);
		std::cout << replace_o.getfilename() << replace_o.gets1() << replace_o.gets2() << std::endl;
	}
	
}