/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:46:53 by aoner             #+#    #+#             */
/*   Updated: 2023/04/15 20:43:53 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//	-----------	Orthodox Canonical Form	-----------
Span::Span(void)
{
	this->_n		= 0;
	this->_count	= 0;
	//this->_v.resize(_n);
}

Span::Span(unsigned int n)
{
	this->_n		= n;
	this->_count	= 0;
//	this->_v.resize(_n);
}

Span::~Span()
{;
}

Span::Span(const Span &copy)
{
	this->_n = copy._n;
	this->_count = copy._count;
	this->_v = copy._v;
}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        this->_v = copy._v;
        this->_n = copy._n;
		this->_count = copy._count;
    }
    return (*this);
}

//	-----------	Member Funtions	-----------
void Span::addNumber(int val)
{
	try
	{
		if (_n != _count)
		{
			_v.push_back(val);
		//	_v.insert(_v.begin() + _count, val);
			std::cout << "_v:: "<< _v[_count] << std::endl; //silinecekkk ////silinecekkkkkk!!!!
		}
		else
			throw Span::TooMuchCount();
		_count++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		//exit(1); //buraya exit koymak yanlış mi?
	}
}

void Span::fill_all(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	try
	{
		if (std::distance(begin, end) > _n - _count)
		{
			_v.insert(_v.end(), begin, begin + (_n - _count));
        	throw TooMuchCount();
		}
		else
		{
			_v.insert(_v.end(), begin, end);
			_count += std::distance(begin, end);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		//exit(1); //burada exit kullanmak doğru mu?
	}
}

int Span::shortestSpan()
{
//	int				min = 0;
	//unsigned int	i = _count;

	try
	{
		if (_count < 2)
			throw Span::TooFewCount();
/*     	std::vector<int> v = _v;
		sort(v.begin(), (v.begin() + _count));
		min = v[i - 1] - v[i - 2];
		for(int temp = 0; i >= 2; i--)
		{
			temp = v[i - 1] - v[i - 2];
			if (temp < min)
				min = temp;
		}
		return (min); */
		std::sort(this->_v.begin(), this->_v.end());
        std::vector<int>::iterator ptr;
        int shortSpan = *(this->_v.end() - 1) - *(this->_v.begin());
        for (ptr = (this->_v.end() - 1); ptr > this->_v.begin() ; ptr--) {
            if(shortSpan > *ptr - *(ptr - 1))
                shortSpan = *ptr - *(ptr - 1);
        }
        return shortSpan;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

int Span::longestSpan()
{
	try
	{
		if (_count < 2)
			throw Span::TooFewCount();
    	std::vector<int> v = _v;
		sort(v.begin(), (v.begin() + _count));
		return (v[_count - 1] - v[0]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

//	-----------	Exception Messages	-----------
const char *Span::TooFewCount::what() const _NOEXCEPT
{
	return("\033[31mToofewcount!!\033[0m");
}

const char* Span::TooMuchCount::what() const _NOEXCEPT
{
	return ("\033[31mThere are already N elements stored!!\033[0m");
}









/* 		std::cout << "front:	" << v.front() << std::endl;
		std::cout << "back:	" << v.back() << std::endl;
		std::cout << "v[0]:	" << v[0]  << std::endl;
		std::cout << "v[end]:	" << v[_count - 1]  << std::endl;
*/