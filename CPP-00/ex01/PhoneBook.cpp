/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:48:25 by aoner             #+#    #+#             */
/*   Updated: 2022/12/14 14:49:54 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

/* class mantığına uygun olarak fieldlarımı private olarak tanımladım
ama bu private fieldlara default değerler atamam gerekiyor.
Fieldlara default değer atamasını burada yapıyoruz.*/
PhoneBook::PhoneBook(void)
{
	this->index = 0;
	this->size = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

/* main içinde phonebook değişkeni oluşturduğum halde phonebook.objects!ine erişemem ÇÜNKÜ PRIVATE.
Bu yüzden public olarak bir fonksiyon tanımlarım ve bunun içine parametre olarak private bölümündeki istediğim field'ı veriririm.
Böylelikle bu public fonksiyondan yararlanarak dolaylı olarak private field'ine erişebilirim.*/
void	PhoneBook::fill_the_objects(string info_c[5])
{
	if (this->size > 7)
		this->index = (this->size % 7) - 1;
	this->objects[this->index].set_First_name(info_c[0]);
	this->objects[this->index].set_Last_name(info_c[1]);
	this->objects[this->index].set_Nick_name(info_c[2]);
	this->objects[this->index].set_Phone_num(info_c[3]);
	this->objects[this->index].set_Secret(info_c[4]);
	this->index++;
	this->size++;
}

static void	display_index_info(Contact object)
{
	cout << "first name:	" << object.get_First_name();
	cout << "\nlast  name:	" << object.get_Last_name();
	cout << "\nnick name:	" << object.get_Nick_name();
	cout << "\nphone num:	" << object.get_Phone_num();
	cout << "\ndark  secret:	" << object.get_Secret();
	cout << endl;
}

static void	display_everyone_info(int end, Contact objects_c[8]) 
{
	int		i;
	int		len;

	i = 0;
	while (i < end)
	{
		cout << "|     "<< i << " |";
		if (strlen(objects_c[i].get_First_name().c_str()) > 10)
		{
			put_space(3);
			cout << objects_c[i].get_First_name().substr(0, 9) << ". |";
		}
		else
		{
			len = 13 - strlen(objects_c[i].get_First_name().c_str());
			put_space(len);
			cout << objects_c[i].get_First_name() << " |";
		}
		if (strlen(objects_c[i].get_Last_name().c_str()) > 10)
		{
			put_space(3);
			cout << objects_c[i].get_Last_name().substr(0, 9) << ". |";
		}
		else
		{
			len = 13 - strlen(objects_c[i].get_Last_name().c_str());
			put_space(len);
			cout << objects_c[i].get_Last_name() << " |";	
		}
		if (strlen(objects_c[i].get_Nick_name().c_str()) > 10)
		{
			put_space(3);
			cout << objects_c[i].get_Nick_name().substr(0, 9) << ". |";	
		}
		else
		{
			len = 13 - strlen(objects_c[i].get_Nick_name().c_str());
			put_space(len);
			cout << objects_c[i].get_Nick_name() << " |";	
		}
		cout << endl;
		i++;
		cout << "------------------------------------------------------" << endl;
	}	
}

void	PhoneBook::display_the_objects(void)
{
	int				end;
	string			input;
	int				val;
	
	end = 0;
	if (this->size <= 8)
		end = this->size;
	else if (this->size > 8)
		end = 8;
	top_framework();
	display_everyone_info(end, this->objects);
	if (this->size >= 1)
	{
		cout << "\001\033[1m\033[37m\002\nDetayli bilgi icin index numarasi giriniz!\n \001\033[0;0m\002" << endl;
		cout << "index: ";
		while (getline(cin, input) && (!is_valid_num(input) || atoi(input.c_str()) > 7 \
		|| atoi(input.c_str()) >= this->size || (input).length() == 0))
		{
			cout << "\033[31mLutfen gecerli bir INDEX numarasi giriniz! \033[0m" << endl;
			cout << "index: ";
		}
		val = atoi(input.c_str());
		display_index_info(this->objects[val]);
	}
	else
		cout << "\001\033[1m\033[37m\002\nindex aramasi icin önce kisi eklmeniz gerekmektedir!\n \001\033[0;0m\002" << endl;
}
