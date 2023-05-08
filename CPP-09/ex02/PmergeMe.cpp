/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:30:10 by aoner             #+#    #+#             */
/*   Updated: 2023/05/08 17:47:27 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	input_ctrl(int ac, char **arg, std::list<int> &_list, std::deque<int> &_deque)
{
	std::string			word;
	std::stringstream	ss;

    for (int i = 1; i < ac; i++)
        ss << arg[i] << " ";
	
    while (ss >> word)
	{
		int		l;
		char	*endptr = NULL;

		l = strtol(word.c_str(), &endptr, 0);
		if (*endptr == '\0' && l >= 0 && l < INT_MAX)
		{
			_list.push_back(l);
			_deque.push_back(l);
		}
		else
			return (false);
	}
	return(true);
}