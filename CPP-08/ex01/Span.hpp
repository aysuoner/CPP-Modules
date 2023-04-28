#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <list>

class Span
{
private:
    std::vector<int>	_v;
	unsigned int		_n;

public:
	Span();
	Span(unsigned int n);
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &copy);

	void	addNumber(int val);
	int		shortestSpan(void);
	int		longestSpan(void);
	void	print_span(void);
	void	add_all( std::vector<int>::iterator begin, std::vector<int>::iterator end);

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