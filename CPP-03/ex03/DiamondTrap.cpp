/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:08:20 by aoner             #+#    #+#             */
/*   Updated: 2023/02/01 21:15:33 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) 
{
	std::cout << "dia def const oluşturuldu..." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "diamond deconst yokedildi" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name): FragTrap(_name), ScavTrap(_name)
{
	std::cout << "diamont trap with name oluşturuldu" << std::endl;
}
