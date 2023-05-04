/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:00:15 by aoner             #+#    #+#             */
/*   Updated: 2023/05/04 14:27:28 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: ./RPN 'expression'";
        return (EXIT_FAILURE);
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

	if (polish_handle(arr, _sVal, _sOperant, count) == true)
	{
		if (_sVal.size() == 1 && _sOperant.size() == 0)
			std::cout << "val:" << _sVal.top();
		else
			std::cout << "derhal";
	}
	else
	{
		std::cout << "mainde yakalandi";
		return(EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}

//bunu yap "8  9 - 9" //invalid
//"3 1 1 1 1 2 * * * + 2 1 5 * + -" //invalid
//"8 4 * 3 9 - + 2 *"  valid res: 52
//"8 4 * 3 9 - + 2"  invalid
//"2 + 3 * 4 / 2 - 1" invalid
//"2 3 * + 4 / 2 - 1" invalid
//"2 3 * 4 6 5 6 2 /"  invalid
//"1 2 1 2 1 2 + * + 3 * -" invalid
// "8 4 6 7 3 9 + * + * -" res: -352

/* 		else if (_sVal.size() >= 2 && i + 1 == count)
		{
			std::cout << "ulaburadacikti bi namussuz";
			return(0);
		} */