/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:11:40 by aoner             #+#    #+#             */
/*   Updated: 2023/01/17 14:51:16 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
{
	weapon = NULL;
	this->name = _name;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& _weapon)
{
	this->weapon = &_weapon;
}

void HumanB::attack()
{
	if (!weapon->getType().empty())
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
