#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>
#include <unistd.h>

template <typename T>
class Array
{
private:
	T				*_arr;
	unsigned int	_size;

public:
    Array(void);

    Array(unsigned int n);

    Array(const Array& other);

    Array& operator=(const Array& other);

    T& operator[](unsigned int i) const;

    unsigned int  size(void) const;

    ~Array(void);

    class OutOfBoundsException : public std::exception
	{
        public:
            virtual const char* what() const throw();
    };
};

template < typename T >
std::ostream& operator<<(std::ostream& out, const Array<T>& arr);

#include "Array.tpp"

#endif