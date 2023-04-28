/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:23:13 by aoner             #+#    #+#             */
/*   Updated: 2023/04/28 12:25:54 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"	

int main()
{
	std::string white_code = "\001\033[1m\033[37m\002";
	std::string reset_code = "\001\033[0;0m\002";
	
	std::cout << white_code << "\n----MutantStack TEST-----" << reset_code << std::endl;

	MutantStack<int> mstack;


	mstack.push(5);
	mstack.push(17);
	mstack.push(20);
	mstack.push(22);

	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "top: " << mstack.top() << std::endl;
	std::cout << "stacksize: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(8);
	mstack.push(737);
	mstack.push(0);


	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::cout << "stackprint: ";
	while(it != ite)
	{
		std::cout << *it << " ";
		++it;
	}

	std::stack<int> s(mstack);
	
	std::cout << white_code << "\n\n----List TEST-----" << reset_code << std::endl;

	std::list <int> l;

	l.push_back(5);
	l.push_back(17);
	l.push_back(20);
	l.push_back(22);

	std::cout << "back: " << l.back() << std::endl;
	l.pop_back();
	std::cout << "back: " << l.back() << std::endl;
	std::cout << "listsize: " << l.size() << std::endl;

	l.push_back(3);
	l.push_back(8);
	l.push_back(737);
	l.push_back(0);

	std::list<int>::iterator i = l.begin();
	std::list<int>::iterator j = l.end();

	std::cout << "stackprint: ";
	while (i != j)
	{
		std::cout << *i << " ";
		i++;
	}
	return 0;
}