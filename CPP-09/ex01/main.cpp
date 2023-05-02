/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:00:15 by aoner             #+#    #+#             */
/*   Updated: 2023/05/02 20:18:22 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int word_count(std::string str) {
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

int main(int argc, char **argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: ./RPN 'expression'";
        return EXIT_FAILURE;
    }

    std::string convrt(argv[1]);
    int count = word_count(convrt);
    std::string arr[count];
    if (fill_and_check_string(convrt, arr, count) == false)
	{
		std::cerr << "bir rakam veya bir islem olmali";
		return(EXIT_FAILURE);
	}
	//count = 5;

	//bunu yap "8  9 - 9"
	
	std::stack<int> _sVal;
	std::stack<char> _sOperant;

	int i = 0;
	int val;
	int first;
	int second;
	char oper;
	while(i < count)
	{
		if (_sVal.size() != 2 && std::isdigit(arr[i][0]))
		{
			val = atoi(arr[i].c_str());
			_sVal.push(val);
			i++;
		}
		else if (_sVal.size() != 2 && !std::isdigit(arr[i][0]))
		{
			std::cout << "ulaaapolish degil" << std::endl;
			return (0);
		}
		if (_sVal.size() == 2 && !std::isdigit(arr[i][0]))
		{
			_sOperant.push(arr[i][0]);
			i++;
		}
		else if (_sVal.size() == 2 && std::isdigit(arr[i][0]))
		{
			std::cout << "polish degil" << std::endl;
			return (0);
		}
		else if (_sVal.size() != 2 && i + 1 == count){
			std::cout << "yakaladumsanuulaaapolish degil" << std::endl;
			return(0);
		}
		if (_sVal.size() == 2 && _sOperant.size() == 1)
		{
			second =_sVal.top();
			_sVal.pop();
			first =_sVal.top();
			_sVal.pop();
			oper =_sOperant.top();
			_sOperant.pop();
			if (oper == '-')
			{
				_sVal.push(first - second);
			}
			else if (oper == '+')
			{
				_sVal.push(first + second);
			}
			else if (oper == '*')
			{
				_sVal.push(first * second);
			}
			else if (oper == '/')
			{
				_sVal.push(first / second);
			}
		}
	}
	std::cout << _sVal.top() << std::endl;
	return(0);
}
