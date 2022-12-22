/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:08:07 by aoner             #+#    #+#             */
/*   Updated: 2022/12/15 16:16:32 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, string name)
{
	if (N < 1)
	{
		cout << "'N' can not contain less than 1 Zombie." << endl;
		return(NULL);
	}
	Zombie	*newz = new Zombie[N]; //burada constructorA gidiyor hepsi sırayla;
	cout << endl;
	if (newz == NULL)
	{
		cout << "Allocation of the zombie_objs failed." << endl;
		return (NULL);
	}
	for (int i = 0; i <= N; i++)
		newz[i].set_name(name);
	return(newz);
}