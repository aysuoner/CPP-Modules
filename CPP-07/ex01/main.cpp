/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:58:04 by aoner             #+#    #+#             */
/*   Updated: 2023/04/25 15:34:32 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char arr3[] = {'a', 'b', 'c', 'd', 'e'};
    std::string arr4[] = { "one", "two", "three", "four", "five" };

    std::cout << "ARR1: " << std::endl;
	::iter<int>(arr1, 5, print_i<int>);
    std::cout << std::endl;

    std::cout << "\nARR2: " << std::endl;
    ::iter<double>(arr2, 5, print_i<double>);
    std::cout << std::endl;

    std::cout << "\nARR3: " << std::endl;
    ::iter<char>(arr3, 5, print_i<char>);
    std::cout << std::endl;

    std::cout << "\nARR4: " << std::endl;
    ::iter<std::string>(arr4, 5, print_i<std::string>);
    std::cout << std::endl;

    return 0;
}
