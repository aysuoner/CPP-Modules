/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:34:37 by aoner             #+#    #+#             */
/*   Updated: 2023/02/01 19:36:03 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//kimi kodlarda virtual ve using değişkenleri kullanılmış bunun sebebini araştır ben kullanmadım.
int	main()
{
	std::cout << "\n\n### TESTING DIAMONDTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		DiamondTrap a;
	/* 	DiamondTrap b("Giga Chadd");
		DiamondTrap c(a);
		std::cout << "\033[34mTesting\033[0m" << std::endl;
		//a.whoAmI();
		a.attack("some super random dude");
		//b.whoAmI();
		b.attack("Chadd-clone");
		//c.whoAmI(); */
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
}