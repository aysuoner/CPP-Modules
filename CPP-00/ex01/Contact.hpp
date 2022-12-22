#ifndef CONTACT_H
# define CONTACT_H

//#include <string>
#include <iostream>

using std:: cout;
using std:: endl;
using std:: string;
using std:: cin;
using std:: getline;

/*contact classım benim içinden N kadar OBJEEEE yaratabileceğim ana modül/şablon
get ve set fonksiyonlarındaki amaç private olarak kullandığım fieldlara dolaylı erişim sağlayabilmek için yaratılan ara mekanizmalardır.
SET fonksiyonu sayesinde ben main içinde verdiğim değeri objelere atayabilmiş olurum.
GET fonksiyonu sayesinde class içindeki değerleri main içinde çağırabilmiş oluyorum*/
class Contact
{
	private:
		string	first_name;
		string	last_name;
		string	nick_name;
		string	phone_num;
		string	secret;
	public:
		void	set_First_name(string f_name){
			Contact::first_name = f_name;
		}
		void	set_Last_name(string l_name){
			Contact::last_name = l_name;
		}
		void	set_Nick_name(string n_name){
			Contact::nick_name = n_name;
		}
		void	set_Phone_num(string p_num){
			Contact::phone_num = p_num;
		}
		void	set_Secret(string scrt){
			Contact::secret = scrt;
		}
		string	get_First_name(){
			return first_name;
		}
		string	get_Last_name(){
			return last_name;
		}
		string	get_Nick_name(){
			return nick_name;
		}
		string	get_Phone_num(){
			return phone_num;
		}
		string	get_Secret(){
			return secret;
		}
};

#endif