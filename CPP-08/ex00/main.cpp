/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:58:09 by aoner             #+#    #+#             */
/*   Updated: 2023/04/09 22:37:58 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::list<int> test;
	test.push_back(155);
	test.push_back(156);
	test.push_back(157);

	std::list<int>::const_iterator	it = test.end();

	try
	{
		it = ::easyfind(test, 155);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != test.end())
		std::cout << *it << " found" << std::endl;

	it = test.end();

	try
	{
		it = ::easyfind(test, 15);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != test.end())
		std::cout << *it << " found" << std::endl;

	return (0);
}