#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <cstdlib>

class Span
{
private:
    std::vector<int>	_v;
	unsigned int		_n;
	unsigned int		_count;

public:
	//ortodoks canon
	Span();
	Span(unsigned int n);
	~Span();

	//member funcs
	void	addNumber(int val);
	void	fill_all( std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int		longestSpan();
	int		shortestSpan();

	class TooMuchCount: public std::exception
	{
  		public:
    		virtual const char* what() const _NOEXCEPT;
	};

	class TooFewCount: public std::exception
	{
		public:
			virtual const char* what() const _NOEXCEPT;
	};

};

#endif