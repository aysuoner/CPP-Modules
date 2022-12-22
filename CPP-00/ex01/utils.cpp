/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:35:03 by aoner             #+#    #+#             */
/*   Updated: 2022/12/10 22:34:50 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	put_space(int len)
{
	while (len > 0 )
	{
		cout << " ";
		len--;
	}
}

void	top_framework(void)
{
	cout << "------------------------------------------------------" << endl;
	cout << "| index |   first name |   last  name |   nick  name |" << endl;
	cout << "------------------------------------------------------" << endl;
	
}

void	welcome_info(void)
{
	cout << "\001\033[1m\033[32m\002\n	phonebook uygulamasina hosgeldiniz!\n \001\033[0;0m\002" << endl;
	cout << "\001\033[1m\033[37m\002	uygulama 3 komuttan olusmaktadir\001\033[0;0m\002" << endl;
	cout << "\001\033[1m\033[37m\002	ADD: rehbere kisi ekler\001\033[0;0m\002" << endl;
	cout << "\001\033[1m\033[37m\002	SEARCH: rehberdeki kisi hakkında detayli bilgi verir\001\033[0;0m\002" << endl;
	cout << "\001\033[1m\033[37m\002	EXIT: phonebook uygulamasindan cikar\001\033[0;0m\002" << endl;
}

int	space_string(string info)
{
	int i;

	i = 0;
	while (info[i] && isspace(info[i]))
		i++;
	if (!info[i]) //yani bosluklardan olusan input;
		return(0);
	return(1); //icinde karakter var.
}

int	is_valid_num(string number)
{
	int i;

	i = 0;
	while (number[i])
	{
		if (number[i] >= 48 && number[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

void	info_ctrl(string *input, string display, int type)
{
	cout << display;
	if (type == 0)
	{
		while (getline(cin, (*input)) && ((*input).length() == 0 || !space_string(*input)))
		{
			cout << "\033[31mBu alan bos birakilamaz!\033[0m" << std::endl;
			cout << display;
		}	
	}
	else if (type == 1)
	{
		while (getline(cin, (*input)) && ((*input).length() == 0 || !is_valid_num(*input)))
		{
			cout << "\033[31mLutfen gecerli bir phone number giriniz!\033[0m" << std::endl;
			cout << display;
		}
	}
}

void	get_info(string info[5])
{
	int i;

	i = 0;
	info_ctrl(&info[i], "first name: ", 0);
	i++;
	info_ctrl(&info[i], "last name: ", 0);
	i++;
	info_ctrl(&info[i], "nick name: ", 0);
	i++;
	info_ctrl(&info[i], "phone num: ", 1);
	i++;
	info_ctrl(&info[i], "dark secret: ", 0);
	cout << "\033[32mContact added successfully.\n\033[0m" << endl;
}