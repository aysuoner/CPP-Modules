/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:14:05 by aoner             #+#    #+#             */
/*   Updated: 2022/12/15 16:14:28 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*zombie_objs;
	int		zombie_n;

	zombie_n = 5;
	zombie_objs = zombieHorde(zombie_n, "Zombik");
	if (zombie_objs == NULL)
		return (0);
	for (int i = 0; i <= zombie_n; i++)
		zombie_objs[i].announce();
	cout << endl;
	delete[] zombie_objs;
	return(0);
}