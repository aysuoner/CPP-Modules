/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:46:53 by aoner             #+#    #+#             */
/*   Updated: 2023/04/13 19:04:58 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
}

Span::Span(unsigned int n)
{
	this->_n = n;
	this->_v.resize(_n);
}

Span::~Span()
{
	
}

void Span::addNumber(int val)
{

	//try-catch blok add!!
	if (this->_n != this->_count)
	{
		_v.insert(_v.begin() + _count, val);	
	}
	else
	{
		printf("count:: %d\n", _count);
		printf("errrrorrr\n");
	}
	//std::cout << _v[_count];
	_count++;
}

