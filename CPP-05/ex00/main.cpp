/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:10:52 by aoner             #+#    #+#             */
/*   Updated: 2023/02/07 23:15:25 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
    {
        Bureaucrat dfd("nazi", 2);
		std::cout << dfd << std::endl;
        dfd.incrementGrade();
		std::cout << dfd << std::endl;
        dfd.incrementGrade();
        dfd.incrementGrade();
        dfd.decrementGrade();
		std::cout << dfd << std::endl;
        dfd.decrementGrade();
		std::cout << dfd << std::endl;
		
    }
    catch(const std::exception& e)
    {
        std::cout << e.what();
    }
	return EXIT_SUCCESS;
}