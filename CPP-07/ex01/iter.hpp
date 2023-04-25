#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T>
void iter(T *arr, int len, void (*func)(const T &))
{
	for(int i=0; i<len; i++)
	{
		func(arr[i]);
    }
}

template <typename T>
void print_i(const T &vak)
{
    std::cout << vak << " ";
}

#endif