/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:14:28 by aoner             #+#    #+#             */
/*   Updated: 2022/12/15 16:07:45 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	cout << "A zombie is created" << endl;
}

Zombie::~Zombie()
{
	cout << _name << ": destroyed" << endl;
}

void Zombie:: set_name(string name)
{
    this->_name = name;
}

void	Zombie::announce(void)
{
	cout << _name << ": BraiiiiiiinnnzzzZ..." << endl;
}
