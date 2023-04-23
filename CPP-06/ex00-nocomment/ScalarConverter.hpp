#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

//bunların hangi fonksiyonlar için kullanıldığını öğren?
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cmath>

class ScalarConverter
{
	public:
		static void			convert(const std::string input);
		~ScalarConverter();
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
};

#endif