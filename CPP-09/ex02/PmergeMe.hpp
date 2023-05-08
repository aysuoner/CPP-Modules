#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <deque>

bool	input_ctrl(int ac, char **arg, std::list<int> &_list, std::deque<int> &_deque);

template <typename T>
T merge(T &left, T &right)
{
    T result;
    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }
    if (!left.empty())
        result.insert(result.end(), left.begin(), left.end());
    if (!right.empty())
        result.insert(result.end(), right.begin(), right.end());
    return result;
}

template <typename T>
T mergesort(T &m)
{
	T			left;
	T			right;
	int			middle;
	typename	T::iterator it;

    middle = m.size() / 2;
	it = m.begin();
    for (int i = 0; i < middle; i++)
	{
        left.push_back(*it);
		it++;
    }
    for (unsigned int i = middle; i < m.size(); i++)
	{
        right.push_back(*it);
		it++;
    }
	if (left.size() > 1)
    	left = mergesort(left);
	if (right.size() > 1)
		right = mergesort(right);

    T result = merge(left, right);
    return result;
}

#endif