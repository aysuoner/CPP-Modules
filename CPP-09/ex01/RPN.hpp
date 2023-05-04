#ifndef PRN_HPP
#define PRN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <sstream> 
#include <array> 
#include <list> 

typedef enum
{ 
  addition			= '+',
  division			= '/',
  subtraction		= '-', 
  multiplication	= '*',
} operant_t; 

int word_count(std::string str);
bool	fill_and_check_string(std::string str, std::string* arr, int count);
bool	polish_handle(std::string const  *arr, std::stack<float> &_sVal, std::stack<char> &_sOperant, int count);

#endif