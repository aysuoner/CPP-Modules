/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:11:03 by aoner             #+#    #+#             */
/*   Updated: 2022/12/15 20:15:09 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	cout << "created weapon_obj..."	<< endl;	
}

Weapon::~Weapon()
{
	cout << "destroyed weapon obj" << endl;
}

string	Weapon::getType() const
{
	return _type;
}

void	Weapon::setType(string type)
{
	Weapon::_type = type;
}