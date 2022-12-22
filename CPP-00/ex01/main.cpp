/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:48:18 by aoner             #+#    #+#             */
/*   Updated: 2022/12/14 14:08:40 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	phonebook;
	string		command;
	string		info[5];

	(void)**argv;
	welcome_info();
	while (argc)
	{
		cout << "\001\033[1;35m\002PhoneBook > \001\033[0;0m\002";
		getline(cin ,command);
		if (command == "ADD")
		{
			get_info(info);
			phonebook.fill_the_objects(info);
		}
		else if (command == "SEARCH")
			phonebook.display_the_objects();
		else if (command == "EXIT")
			exit(0);	
		else
			cout << "lutfen gecerli bir komut giriniz!(ADD, SEARCH, OR EXIT)"<< endl;
	}
}