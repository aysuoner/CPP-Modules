/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:00:15 by aoner             #+#    #+#             */
/*   Updated: 2023/05/25 12:26:24 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* Ters Lehçe gösterimi (RPN), parantez ve parantez gibi ayırıcılar
kullanılmadan matematiksel ifadeleri iletmek için bir yöntemdir.
İşlem soldan sağa okunur, ancak bir operatöre her ulaşıldığında yürütme gerçekleştirilir
ve her zaman son iki sayıyı işlenen olarak kullanır.
RPN, birkaç nedenden dolayı daha hızlı hesaplamalara yol açar.
Birincisi, depolanacak daha az bilgi olması.
Bu nedenle, ifade ((5 - 3) * 2) için dokuz karakter depolamak yerine,
RPN kullanan bilgisayarların yalnızca 5 3 - 2 * ifadesiyle beş karakter depolaması gerekir. */

int main(int argc, char **argv)
{
    if (argc != 2)
	{
        std::cerr << "Usage: ./RPN 'expression'";
        return (EXIT_FAILURE);
    }
	
	RPN::param = argv[1];
	RPN::word_count(RPN::param);
    std::string arr[RPN::count];
	
    if (RPN::fill_and_check_string(arr) == false)
	{
		std::cerr << "The token must be a digit or operation '+ - / *'";
		return(EXIT_FAILURE);
	}

	if (RPN::polish_handle(arr) == true)
	{
		if (RPN::_sVal.size() == 1 && RPN::_sOperant.size() == 0)
			std::cout << RPN::_sVal.top();
		else
			std::cout << "invalid input: not enough operations!";
	}
	else
	{
		std::cout << "invalid input: not enough numbers";
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
