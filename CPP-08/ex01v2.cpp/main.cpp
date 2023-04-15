/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:53:15 by aoner             #+#    #+#             */
/*   Updated: 2023/04/15 22:20:54 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//test geliştir...
int main(void)
{
	//color_code
	std::string white_code = "\001\033[1m\033[37m\002";
	std::string reset_code = "\001\033[0;0m\002";
	
	std::cout << white_code << "\n----AaddNumber() TEST-----" << reset_code << std::endl;
	Span sp1(15);
	sp1.addNumber(10);
	sp1.addNumber(20);
	sp1.addNumber(30);
	sp1.addNumber(40);
	sp1.print_span();

	std::cout << white_code << "\n\n----fill all() TEST - 1-----" << reset_code << std::endl;
	std::vector<int> v1;
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(80);
	v1.push_back(90);
	v1.push_back(100);
	sp1.fill_all(v1.begin(), v1.end());
	sp1.print_span();

	std::cout << white_code << "\n\n----range TEST-----" << reset_code << std::endl;
	std::cout << "short:	" << sp1.shortestSpan()	<< std::endl;
	std::cout << "long:	" << sp1.longestSpan()	<< std::endl;

	Span sp2(23);
	std::cout << "long:	"  << sp2.longestSpan()	<< std::endl;
	std::cout << "short:	" << sp2.shortestSpan() << std::endl;

	std::cout << white_code << "\n----RANDOM TEST -----" << reset_code << std::endl;	
	Span sp3(200);
	std::vector<int> v2;
	std::srand(std::time(NULL));
	int val;
	for (int i = 0; i <= 150; i++)
	{
		if (i % 2 == 0)
			val = (std::rand() % ((i + 1) % i + 3) * 1);
		else if (i % 2 == 1)
			val = (std::rand() % (i + 1) % i + 6) * 7;
		v2.push_back(val);
	}
	sp3.fill_all(v2.begin(), v2.end());
	sp3.print_span();

	std::cout << white_code << "\n\n----range TEST-----" << reset_code << std::endl;
	std::cout << "long:	"  << sp3.longestSpan()	<< std::endl;
	std::cout << "short:	" << sp3.shortestSpan() << std::endl;
	
	return 0;
}
