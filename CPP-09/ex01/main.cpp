/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:00:15 by aoner             #+#    #+#             */
/*   Updated: 2023/05/23 22:15:11 by aoner            ###   ########.fr       */
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
	
	RPN::param = argv[1];
	RPN::word_count(RPN::param);
    std::string arr[RPN::count]; //düz string haline getir.
	
    if (RPN::fill_and_check_string(arr) == false)
	{
		std::cerr << "bir rakam veya bir islem olmali";
		return(EXIT_FAILURE);
	}

	if (RPN::polish_handle(arr) == true)
	{
		if (RPN::_sVal.size() == 1 && RPN::_sOperant.size() == 0)
			std::cout << "val:" << RPN::_sVal.top();
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

//"8  9 - 9" //invalid
//"3 1 1 1 1 2 * * * + 2 1 5 * + -" //invalid
//"8 4 * 3 9 - + 2 *"  valid res: 52
//"8 4 * 3 9 - + 2"  invalid
//"2 + 3 * 4 / 2 - 1" invalid
//"2 3 * + 4 / 2 - 1" invalid
//"2 3 * 4 6 5 6 2 /"  invalid
//"1 2 1 2 1 2 + * + 3 * -" invalid
// "8 4 6 7 3 9 + * + * -" res: -352
