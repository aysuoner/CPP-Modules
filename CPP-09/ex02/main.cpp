/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:31:15 by aoner             #+#    #+#             */
/*   Updated: 2023/05/08 18:39:12 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*merge: büyük dizeleri hızlı sıralar. recursive bir fonksiyonun
dizeyi daha fazla bölünemeyene dek bölüdüğün düşün
merge sort first divides the whole array iteratively into equal halves,
unless the atomic values are achieved.

This algorithm is one of the simplest algorithm with simple implementation
Basically, Insertion sort is efficient for small data values
*/

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Usage ./PmergeMe 'positive integer sequence'";
		return(EXIT_FAILURE);
	}

	std::list<int>		_list;
	std::deque<int>		_deque;

	if (input_ctrl(argc, argv, _list, _deque) == false)
	{
		std::cerr << "parameter must be a positive integer value";
		return (EXIT_FAILURE);
	}
	
	//PRINT BEFORE///
	std::cout << "Before:	";
 	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	//SORT the LIST and TAKE TIME
	std::clock_t start_lst = std::clock();
    std::list<int> sorted_list = mergesort(_list);
    std::clock_t end_lst = std::clock();
	
	//PRINT AFTER
	std::cout << "After:	";
 	for (std::list<int>::iterator it = sorted_list.begin(); it != sorted_list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	//PRINT TIME for LIST
	double elapsed_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC * 10;
    std::cout << "Time to process a range of " << _list.size() << " elements with list sort: " << elapsed_lst << " us" << std::endl;
	
	//SORT the DEQUE and TAKE TIME,
	start_lst = std::clock();
    std::deque<int> sorted_deque = mergesort(_deque);
    end_lst = std::clock();

	//PRINT TIME for DEQUE
	elapsed_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC * 10;
    std::cout << "Time to process a range of " << _deque.size() << " elements with list sort: " << elapsed_lst << " us" << std::endl;

    return 0;
}
