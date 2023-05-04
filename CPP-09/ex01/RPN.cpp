/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:59:41 by aoner             #+#    #+#             */
/*   Updated: 2023/05/04 14:09:39 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	polish_handle(std::string const  *arr, std::stack<float> &_sVal, std::stack<char> &_sOperant, int count)
{
	int		i = 0;
	float	val;
	float	first;
	float	second;
	char	oper;

	while(i < count)
	{
		if (isdigit(arr[i][0]))
		{
			val = atof(arr[i].c_str());
			_sVal.push(val);
		}
		else if (!isdigit(arr[i][0]) && _sVal.size() < 2)
		{
			//sorunun ne oldugunu spesifik goster.
			return (false);
		}
		else if (!isdigit(arr[i][0]))
		{
			_sOperant.push(arr[i][0]);
		}
		if (_sVal.size() >= 2 && _sOperant.size() >= 1)
		{
			oper = _sOperant.top();
			_sOperant.pop();
			second = _sVal.top();
			_sVal.pop();
			first = _sVal.top();
			_sVal.pop();
			switch (oper)
			{
				case addition :
					_sVal.push(first + second);
					break;
				case  division :
					_sVal.push(first / second);
					break;
				case subtraction :
					_sVal.push(first - second);
					break;
				case multiplication :
					_sVal.push(first * second);
					break;
			}
		}
		i++;
	}
	return (true);
}

int word_count(std::string str)
{
    std::stringstream ss(str);  
    std::string word;
    int count = 0;
    while (ss >> word) {
        count++;
    }
    return count;
}

bool	fill_and_check_string(std::string str, std::string* arr, int count)
{
    std::stringstream ss(str);
    std::string word;
    for (int i = 0; i < count; i++)
	{
        ss >> arr[i];
		if (arr[i].length() != 1) {
				return(false);
		}
		else if (!std::isdigit(arr[i][0]) && arr[i][0] != '-' && arr[i][0] != '+' \
				&& arr[i][0] != '*' && arr[i][0] != '/') {
			return(false);
		}
	}
	return(true);
}
