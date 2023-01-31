/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:34:37 by aoner             #+#    #+#             */
/*   Updated: 2023/01/31 14:36:04 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//kimi kodlarda virtual ve using değişkenleri kullanılmış bunun sebebini araştır ben kullanmadım.
int	main()
{
	//FragTrap 	def;
	FragTrap	temp("Daniel");
	FragTrap	Daniel("No name");

	/* Assignment check */
	temp.setEnergyPoints(8);
	Daniel = temp;

	/* Info */
	std::cout << "\n---------- FragTrap Daniel ----------" << std::endl;
	std::cout << "Hitpoints: " << Daniel.getHitPoints() << " ";
	std::cout << "Energy: " << Daniel.getEnergyPoints() << " ";
	std::cout << "Attack Damage: " << Daniel.getAttackDamage() << " ";
	std::cout << "Status: Active" << std::endl;

	/* Test */
	std::cout << "\nStart attacking...\n" << std::endl;

	Daniel.attack("Sharks");
	Daniel.attack("Pirates");
	Daniel.takeDamage(3);
	Daniel.takeDamage(14);
	Daniel.beRepaired(10);
	Daniel.highFivesGuys();
	Daniel.attack("Dragon");
	Daniel.attack("Spirits");
	Daniel.attack("Kings");
	

	std::cout << "\nFights are over...\n" << std::endl;
}
