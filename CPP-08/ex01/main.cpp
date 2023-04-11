/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:46:57 by aoner             #+#    #+#             */
/*   Updated: 2023/04/11 19:14:58 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(1);
        sp.addNumber(9);
        sp.addNumber(11);

        // using addRange memeber function
        std::vector<int> v;
        v.push_back(6);
        v.push_back(3);
        v.push_back(1);
        v.push_back(9);
        v.push_back(11);
        sp.addRange(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception found " << e.what() << '\n';
    }

	try
    {
        Span sp = Span(5);
        std::vector<int> v = {13, 7, 4, 8};
        sp.addRange(v.begin(), v.end()); // add another range of numbers using iterators
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception found " << e.what() << '\n';
    }
	
    return 0;
}
 */

int main()
{
    try
    {
        Span sp = Span(104);
		std::srand(std::time(NULL));
        for (int i = 0; i < 100; i++)
        {
            sp.addNumber(i);
        }
	
        std::vector<int> v;
		v.push_back(std::rand() % 1000);
		std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 1 saniye bekle
		v.push_back(std::rand() % 1000);
		std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 1 saniye bekle
		v.push_back(std::rand() % 1000);
		std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 1 saniye bekle
		v.push_back(std::rand() % 1000);
        sp.addRange(v.begin(), v.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}