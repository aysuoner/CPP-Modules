/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:10:52 by aoner             #+#    #+#             */
/*   Updated: 2023/02/06 23:26:27 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
    {
        throw Bureaucrat("nazi", 1234);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << '\n';
	}
}