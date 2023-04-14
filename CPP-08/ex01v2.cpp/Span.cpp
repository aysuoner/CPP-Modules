/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:46:53 by aoner             #+#    #+#             */
/*   Updated: 2023/04/14 17:15:51 by aoner            ###   ########.fr       */
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

void Span::addNumber(int val)
{
	try
	{
		if (this->_n != this->_count)
		{
			_v.insert(_v.begin() + _count, val);
			std::cout << "_v:: "<< _v[_count] << std::endl;
		}
		else
			throw Span::TooMuchCount();
		_count++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1); //buraya exit koymak yanlış mi?
	}
}

void Span::fill_all(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while ((begin != end))
	{
		addNumber(*begin);
		begin++;
	}
}

const char* Span::TooMuchCount::what() const _NOEXCEPT
{
	return ("There are already N elements stored!!\n");
}

int Span::shortestSpan(Span span)
{
	unsigned int i = _count;
	int range = 0;
	int temp = 0;
	sort(span._v.begin(), (span._v.begin() + _count));
	while(i >= 2)
	{
		temp = span._v[i - 1] - span._v[i - 2];
		if (i == _count)
			range = temp;
		else if (temp <= range)
			range = temp;
		i--;
	}
	return (range);
}

int Span::longestSpan(Span span)
{
	sort(span._v.begin(), (span._v.begin() + _count));
	return (span._v[_count - 1] - span._v[0]);
}

/* void	Span::fill_all(std::vector<int> vector)
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
} */