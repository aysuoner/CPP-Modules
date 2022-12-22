#ifndef UTILS_H
# define UTILS_H

#include <string>
#include <iostream>
#include <iomanip>

#include "Contact.hpp"
#include "PhoneBook.hpp"

using std:: cout;
using std:: endl;
using std:: string;
using std:: cin;
using std:: getline;

void	welcome_info(void);
void	put_space(int len);
void	top_framework(void);
int		space_string(string info);
int		is_valid_num(string number);
int		is_valid_num(string number);
void	info_ctrl(string *input, string display, int type);
void	get_info(string info[5]);

#endif