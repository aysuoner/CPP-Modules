/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:05:40 by aoner             #+#    #+#             */
/*   Updated: 2023/01/17 00:00:37 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon):_weapon(weapon) //?neden böyle
{
	this->_name = name;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	if (_weapon.getType().empty())
		std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
