/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:53:15 by aoner             #+#    #+#             */
/*   Updated: 2023/04/15 20:00:29 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//test geliştir...
int main(void)
{
	//color_code
	std::string white_code = "\001\033[1m\033[37m\002";
	std::string reset_code = "\001\033[0;0m\002";
	
	std::cout << white_code << "\n----AaddNumber() TEST-----\n" << reset_code << std::endl;
	Span sp1(15);
	sp1.addNumber(10);
	sp1.addNumber(20);
	sp1.addNumber(30);
	sp1.addNumber(40);

	std::cout << white_code << "\n----fill all() TEST-----\n" << reset_code << std::endl;
	std::vector<int> v1;
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(80);
	v1.push_back(90);
	v1.push_back(100);
	sp1.fill_all(v1.begin(), v1.end());

	std::cout << white_code << "\n----range TEST-----\n" << reset_code << std::endl;
	std::cout << "shortest:" << sp1.shortestSpan()	<< std::endl;
	std::cout << "longeest:" << sp1.longestSpan()	<< std::endl;

	Span sp2(23);
	std::cout << "longest2:"  << sp2.longestSpan()	<< std::endl;
	std::cout << "shortest2:" << sp2.shortestSpan() << std::endl;
	return 0;
}
