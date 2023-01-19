/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:59:49 by aoner             #+#    #+#             */
/*   Updated: 2023/01/19 17:16:37 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	std::string	lvl;
	Harl harl_o;
    std::cout << "The program is active. Enter a level (DEBUG, INFO, WARNING or ERROR).\nEXIT is for quit." << std::endl;
	do
	{
		std::cin >> lvl;
        harl_o.complain(lvl);
	} while (lvl != "EXIT");
	return EXIT_SUCCESS;
}
