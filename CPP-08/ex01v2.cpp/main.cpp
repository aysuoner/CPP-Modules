/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:53:15 by aoner             #+#    #+#             */
/*   Updated: 2023/04/14 17:16:57 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* template <typename T>
void    printv(std::vector<T> &v)
{
    //std::vector<int>::iterator i = v.begin(); //tek int için geçerli
    typename std::vector<T>::iterator i = v.begin(); //bu ise tipini işlem sırasında belirleyecektir typename olduğu için
    while (i != v.end())
        std::cout << *i++ << " ";
    std::cout << std::endl;
}*/

int main(void)
{
	Span sp1(56);
	sp1.addNumber(42);
	sp1.addNumber(42);
	sp1.addNumber(44);
	sp1.addNumber(47);

	std::vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);

	sp1.fill_all(v1.begin(), v1.end());
	//sp1.fill_all(v1); //böyle yaparsam referansı ile nasıl gönderebilirim?

	//bunların da referanslarını göndermek daha iyi olur!!!
	//try catch yapmalısın eleman 0 ise onu yappp
	std::cout << "shortsssstt:" << sp1.shortestSpan(sp1) << std::endl;
	std::cout << "longesssst:" << sp1.longestSpan(sp1) << std::endl;
	
	return 0;
}