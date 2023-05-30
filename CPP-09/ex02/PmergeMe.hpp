#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <deque>

bool	input_ctrl(int ac, char **arg, std::list<int> &_list, std::deque<int> &_deque);

template<typename T>
void insertionSort(T& m)
{
	int temp;
    typename T::iterator it;
	typename T::iterator prev;
	typename T::iterator j;
    for (it = m.begin(); it != m.end(); ++it)
	{
        temp = *it;
        j = it;
        while (j != m.begin()) {
            prev = j;
            --prev;
            if (*prev > temp) {
                *j = *prev;
                --j;
            }
            else
                break;
        }
        *j = temp;
    }
}

template <typename T>
void mergeInsertsort(T& m)
{
    size_t	len = m.size();
	size_t	threshold = 100;

	if (len > threshold)
	{
		typename T::iterator begin = m.begin();
		typename T::iterator mid = m.begin();
		std::advance(mid, m.size() / 2);
		typename T::iterator end = m.end();
		T left(begin, mid);
    	T right(mid, end);
		if (left.size() > 1)
			mergeInsertsort(left);
		if (right.size() > 1)
    		mergeInsertsort(right);
		std::merge(left.begin(), left.end(), right.begin(), right.end(), m.begin());
	}
    else
    	insertionSort(m);
}

#endif