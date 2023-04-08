/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:58:04 by aoner             #+#    #+#             */
/*   Updated: 2023/04/08 21:37:41 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char arr3[] = {'a', 'b', 'c', 'd', 'e'};
    std::string arr4[] = { "one", "two", "three", "four", "five" };

    std::cout << "\narr1: " << std::endl;
    iter(arr1, 5, &print<int>);
    std::cout << std::endl;

    std::cout << "\narr2: " << std::endl;
    iter(arr2, 5, &print<double>);
    std::cout << std::endl;

    std::cout << "\narr3: " << std::endl;
    iter(arr3, 5, &print<char>);
    std::cout << std::endl;

    std::cout << "\narr4: " << std::endl;
    iter(arr4, 5, &print<std::string>);
    std::cout << std::endl;

    return 0;
}
