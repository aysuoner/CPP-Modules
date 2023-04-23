#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

//bunların hangi fonksiyonlar için kullanıldığını öğren?
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cerrno>

class ScalarConverter
{
	public:
		static void			convert(const std::string input);
		static std::string	getType(std::string input); //içeride çağır burayı sil

		~ScalarConverter();
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
};

#endif