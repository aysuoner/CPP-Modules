/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:11:24 by aoner             #+#    #+#             */
/*   Updated: 2023/04/25 20:50:03 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*!!!!!!!!!MAKEFILE DOĞRU MU KONTROL ETTİR OKULDA!!!!*/

#define MAX_VAL 750
int main(int, char**)
{

		Array<std::string> strarray(3);
	strarray[0] = "Hello";
	strarray[1] = "World";
	strarray[2] = "!";

	try {
		for (size_t i = 0; i < strarray.size(); i++) {
			std::cout << "strarray[" << i << "] = " << strarray[i] << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
	
	Array<int> tmp = numbers;
	Array<int> test(tmp);

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
