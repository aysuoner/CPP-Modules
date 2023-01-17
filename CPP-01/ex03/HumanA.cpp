/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:05:40 by aoner             #+#    #+#             */
/*   Updated: 2023/01/17 13:57:07 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* this weapon->_weapon olarak aşağıda eşitleninde hata veriyor.
referans üyelerinin oluşturma sırasında initilaze edilmesi gerekmektedir
Reference and const members must be initialized in a member-initialization list
cost üyelerin bildiğimiz gibi bir başlangış değeri vardır. C+++taki referansların da bir başlangıç değerleri vardır.
o yüzden initilaze edilirken initialisation list'te başlatılması gerekir.Yani bildirildikleri satırda başlatılmaları gerekmektedir...
Body içinde değil.*/
HumanA::HumanA(std::string _name, Weapon& _weapon): weapon(_weapon)
{
	//this->weapon = _weapon;
	this->name = _name;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	if (!weapon.getType().empty())
		std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
