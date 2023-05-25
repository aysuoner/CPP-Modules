#ifndef PRN_HPP
#define PRN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <sstream>

typedef enum
{ 
  addition			= '+',
  division			= '/',
  subtraction		= '-', 
  multiplication	= '*',
} operant_t; 

class RPN
{
	private:
		RPN();
		RPN(const RPN &);
		RPN &operator=(const RPN &);

	public:
		static std::string	param;
		static int			count;
		static float		val;
		static float		first;
		static float		second;
		static std::stack<float> _sVal;
		static std::stack<char> _sOperant;

		static	void	word_count(std::string param);
		static bool	fill_and_check_string(std::string* arr);
		static bool	polish_handle(std::string const  *arr);
		~RPN();
};

#endif