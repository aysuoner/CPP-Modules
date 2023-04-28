/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:58:09 by aoner             #+#    #+#             */
/*   Updated: 2023/04/28 11:28:07 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::string white_code = "\001\033[1m\033[37m\002";
	std::string reset_code = "\001\033[0;0m\002";
	
	std::cout << white_code << "\n----list<> TEST-----" << reset_code << std::endl;

	std::list<int> test;	
	std::list<int>::iterator it;
	
	test.push_back(155);
	test.push_back(156);
	test.push_back(157);
	
	try
	{
		it = ::easyfind(test, 156);
		std::cout << "Value found at index " << std::distance(test.begin(), it) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		it = ::easyfind(test, 15);
		std::cout << "Value found at index " << std::distance(test.begin(), it) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << white_code << "\n----vector<> TEST-----" << reset_code << std::endl;
	
	std::vector<int> test2 (4, 10);
	std::vector<int>::iterator it_2;
	
	test2.push_back(13);
	test2.push_back(9);
	test2.push_back(8);
	test2.push_back(3);
    test2.insert(test2.begin() + 2, 200);

	try
	{
		it_2 = ::easyfind(test2, 200);
		std::cout << "Value found at index " << std::distance(test2.begin(), it_2) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		it_2 = ::easyfind(test2, 0);
		std::cout << "Value found at index " << std::distance(test2.begin(), it_2) << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
