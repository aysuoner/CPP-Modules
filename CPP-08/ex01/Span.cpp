/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:46:53 by aoner             #+#    #+#             */
/*   Updated: 2023/04/28 14:58:11 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//	-----------	Orthodox Canonical Form	-----------
Span::Span(void)
{
	this->_n = 0;
}

Span::Span(unsigned int n)
{
	this->_n = n;
}

Span::~Span()
{;
}

Span::Span(const Span &copy)
{
	this->_n = copy._n;
	this->_v = copy._v;
}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        this->_v = copy._v;
        this->_n = copy._n;
    }
    return (*this);
}

//	-----------	Member Functions -----------
void Span::addNumber(int val)
{
	try
	{
		if (this->_v.size() == this->_n)
			throw TooMuchCount();
		else
			this->_v.push_back(val);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Span::add_all(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	try
	{
		if (std::distance(begin, end) + _v.size() > _n)
		{
			_v.insert(_v.end(), begin, begin + (_n - _v.size()));
        	throw TooMuchCount();
		}
		else
			_v.insert(_v.end(), begin, end);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int Span::longestSpan(void)
{
	try
	{
		if (_v.size() < 2)
			throw TooFewCount();
		else
		{
       		 std::sort(_v.begin(), _v.end());
       		 int max = _v.back() - _v.front();
       		 return max;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

int Span::shortestSpan(void)
{
	try
	{
		if (_v.size() < 2)
			throw TooFewCount();
		else
		{
			std::vector<int> v = _v;
			std::sort(v.begin(), v.end());
			std::vector<int> differences(v.size());
			std::adjacent_difference(v.begin(), v.end(), differences.begin());
			std::vector<int>::iterator ptr = differences.begin() + 1;
			int min = *ptr;
			for (; ptr != differences.end(); ++ptr)
			{
				if (*ptr < min)
					min = *ptr;
			}
			return (min);
        }
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

void	Span::print_span(void)
{
	std::vector<int>::iterator begin = _v.begin();
	for( int i = 0; begin != _v.end(); i++, begin++)
	{
		std::cout << " " << *(_v.begin() + i);
	}
}

//	-----------	Exception Messages -----------
const char *Span::TooFewCount::what() const _NOEXCEPT
{
	return("\033[31m\nToofewcount!!\033[0m");
}

const char* Span::TooMuchCount::what() const _NOEXCEPT
{
	return ("\033[31m\nThere are already N elements stored!!\n\033[0m");
}
