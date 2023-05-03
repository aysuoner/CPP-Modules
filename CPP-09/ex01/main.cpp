/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:00:15 by aoner             #+#    #+#             */
/*   Updated: 2023/05/03 20:24:08 by aoner            ###   ########.fr       */
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
	std::stack<float> _sVal;
	std::stack<char> _sOperant;

	int		i = 0;
	float	val;
	float	first;
	float	second;
	char	oper;
	//bunu yap "8  9 - 9" //invalid
	//"3 1 1 1 1 2 * * * + 2 1 5 * + -" //invalid
	//"8 4 * 3 9 - + 2 *"  valid res: 54
	//"8 4 * 3 9 - + 2"  invalid
	//"2 + 3 * 4 / 2 - 1" invalid
	//"2 3 * 4 6 5 6 2 /"  invalid
	while(i < count)
	{
		if (isdigit(arr[i][0]))
		{
			val = atof(arr[i].c_str());
			_sVal.push(val);
		}
		else if (!isdigit(arr[i][0]) && _sVal.size() < 2)
		{

			//hangi operator olduğunu hata mesajında göster.
			std::cout << "uladursin";
			return(0);
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
/* 		else if (_sVal.size() >= 2 && i + 1 == count)
		{
			std::cout << "ulaburadacikti bi namussuz";
			return(0);
		} */
		i++;
	}
	if (_sVal.size() == 1 && _sOperant.size() == 0)
		std::cout << "val:" << _sVal.top();
	else
		std::cout << "burda da yakalandunnnnkacamazsunbenden";
	return(0);
}
