/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:53:15 by aoner             #+#    #+#             */
/*   Updated: 2023/04/15 18:14:28 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//test geliştir...
int main(void)
{
	Span sp1(15);
	sp1.addNumber(42);
	sp1.addNumber(100);
	sp1.addNumber(44);
	sp1.addNumber(47);
	
	std::vector<int> v1;
	v1.push_back(10);
	v1.push_back(59);
	v1.push_back(54);
	v1.push_back(143);
	v1.push_back(50);
	v1.push_back(40);

	sp1.fill_all(v1.begin(), v1.end());
	
	//range test
	std::cout << "shortest:" << sp1.shortestSpan()	<< std::endl;
	std::cout << "longeest:" << sp1.longestSpan()	<< std::endl;

	//toofewspan test
	Span sp2(23);
	std::cout << "longest2:"  << sp2.longestSpan()	<< std::endl;
	std::cout << "shortest2:" << sp2.shortestSpan() << std::endl;
	return 0;
}
