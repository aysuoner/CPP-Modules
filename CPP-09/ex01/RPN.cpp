/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:59:41 by aoner             #+#    #+#             */
/*   Updated: 2023/05/23 22:16:14 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int		RPN::count = 0;
float	RPN::val = 0;
float	RPN::first = 0;
float	RPN::second = 0;
std::string RPN::param = "";
std::stack<float> RPN::_sVal;
std::stack<char> RPN::_sOperant;

RPN::RPN(/* args */)
{
}

RPN::~RPN()
{
}

void	RPN::word_count(std::string param)
{
    std::stringstream ss(param);  
    std::string word;
    while (ss >> word)
        count++;
}


/* +3 +6 gibi sayılar olmamalı mı? */
bool	RPN::fill_and_check_string(std::string* arr)
{
    std::stringstream ss(param);
    std::string word;
    for (int i = 0; i < count; i++)
	{
        ss >> arr[i];
		if (arr[i].length() != 1) {
				return(false);
		}
		else if (!std::isdigit(arr[i][0]) && arr[i][0] != '-' && arr[i][0] != '+' \
				&& arr[i][0] != '*' && arr[i][0] != '/')
		{
			return(false);
		}
	}
	return(true);
}

bool	RPN::polish_handle(std::string const *arr)
{
	int		i = 0;
	char	oper;

	//bunu ikiye böl;
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
