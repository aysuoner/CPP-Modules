#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>


class Span
{
private:
    std::vector<int>	_v;
	unsigned int		_n;
	unsigned int		_count;

public:
	Span();
	Span(unsigned int n);
	~Span();
	void	addNumber(int val);
	//void	fill_all(std::vector<int> vector);
	void	fill_all( std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int		longestSpan(Span span);
	int		shortestSpan(Span span);



	class TooMuchCount: public std::exception
	{
  		public:
    		virtual const char* what() const _NOEXCEPT;
	};

};

#endif