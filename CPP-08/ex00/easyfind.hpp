#ifndef EASYFIND_HPP	
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

class NotFoundException: public std::exception
{
	public:
			virtual const char *what() const throw()
			{
				return ("Not found");
			}
};

template< typename T>
typename T::iterator easyfind(T &src, int i)
{
	typename T::iterator	it_ptr;

	it_ptr = find(src.begin(), src.end(), i);
	if (it_ptr == src.end())
	{
		throw (NotFoundException());
	}
	return (it_ptr);
}


#endif