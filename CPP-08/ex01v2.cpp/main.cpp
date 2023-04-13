/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:53:15 by aoner             #+#    #+#             */
/*   Updated: 2023/04/13 19:05:11 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

unsigned int Span::_count = 0;

/* template <typename T>
void    printv(std::vector<T> &v)
{
    //std::vector<int>::iterator i = v.begin(); //tek int için geçerli
    typename std::vector<T>::iterator i = v.begin(); //bu ise tipini işlem sırasında belirleyecektir typename olduğu için
    while (i != v.end())
        std::cout << *i++ << " ";
    std::cout << std::endl;
} */

int main(void)
{
	Span sp1(3);
	sp1.addNumber(42);
	sp1.addNumber(43);
	sp1.addNumber(44);
	sp1.addNumber(47);

	return 0;
}