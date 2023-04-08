#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &src1, T &src2)
{
	T temp;
	temp = src2;
	src2 = src1;
	src1 = temp;
}

template <typename T>
T max(T &src1, T &src2)
{
	return( src1 > src2 ? src1 : src2);
}

template <typename T>
T min(T &src1, T &src2)
{
	return (src1 < src2 ? src1 : src2);
}

#endif
