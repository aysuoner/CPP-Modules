#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

using std:: cout;
using std:: endl;
using std:: string;
using std:: cin;
using std:: getline;

/* phonebook classım ile de kaç tane OBJE YARATACAKSAM ONU AYARLADIM
PDF benden en fazla 8 tane obje yaratmamı istediği için
ben STATİK OLARAK 8 TANE CONTACT CLASSINA BAĞLI OBJE OLUŞTURDUM */
class PhoneBook
{
	private:
		Contact	objects[8];
		int		size;
		int		index;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	fill_the_objects(string info_c[5]);
		void	display_the_objects(void);
		//void	display_everyone_info(int end, Contact objects_c[8]);
		//void	display_index_info(Contact object);
};

#endif