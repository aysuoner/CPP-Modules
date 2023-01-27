/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:34:37 by aoner             #+#    #+#             */
/*   Updated: 2023/01/27 20:13:16 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	Jack("Aysu");
	
	std::cout << "\nStart attacking...\n" << std::endl;

	Jack.attack("Sharks");
	Jack.attack("Pirats");
	Jack.takeDamage(3);
	Jack.takeDamage(4);
	Jack.attack("kekeke");
	Jack.beRepaired(8);
	Jack.attack("Dragon");
	Jack.attack("Spirits");
	Jack.attack("Lions");
	Jack.attack("Kings");

	std::cout << "\nFights are over..." << std::endl;
	
}