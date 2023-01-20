/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:59:49 by aoner             #+#    #+#             */
/*   Updated: 2023/01/20 13:04:53 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl_o;
 	if (argc != 2)
		return EXIT_FAILURE;
    harl_o.complain(argv[1]);
	return EXIT_SUCCESS;
}
