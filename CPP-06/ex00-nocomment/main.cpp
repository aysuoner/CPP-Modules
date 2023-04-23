/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:18:22 by aoner             #+#    #+#             */
/*   Updated: 2023/04/23 17:57:05 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [input]" << std::endl;
		return (0);
	}
	ScalarConverter::convert(std::string(argv[1]));
}