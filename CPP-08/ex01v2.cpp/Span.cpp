/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:46:53 by aoner             #+#    #+#             */
/*   Updated: 2023/04/13 22:54:36 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
}

Span::Span(unsigned int n)
{
	this->_n = n;
	this->_count = 0;
	this->_v.resize(_n);
}

Span::~Span()
{
	
}

int	Span::get_count()const
{
	return(_count);
}

void Span::addNumber(int val)
{

	//try-catch blok add!!
	if (this->_n != this->_count)
	{
		_v.insert(_v.begin() + _count, val);
		std::cout << "_v:: "<< _v[_count] << std::endl;
	}
	else
	{
		printf("count:: %d\n", _count);
		printf("errrrorrr\n");
	}
	//std::cout << _v[_count];
	_count++;
}

void	Span::fill_all(std::vector<int> vector)
{
	std::vector<int>::iterator begin = vector.begin();
	std::vector<int>::iterator end = vector.end();
//	printf("countTTTTT:: %d n::%d\n\n\n", _count, _n);
	while ((begin != end) && (_n != _count))
	{
		addNumber(*begin);
		begin++;
	}
	//throw
//	printf("count:: %d n::%d\n", _count, _n);
//	printf("errrrKKKKK\n");
}
