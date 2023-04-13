#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
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
	void	fill_all(std::vector<int> vector);
	int		get_count() const;


};

#endif