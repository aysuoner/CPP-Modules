/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:18:09 by aoner             #+#    #+#             */
/*   Updated: 2023/04/23 12:38:55 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &) {}

ScalarConverter	& ScalarConverter::operator=(ScalarConverter const &)
{ return *this; }

ScalarConverter::~ScalarConverter() {}

void	printDouble(double d)
{
	std::cout << "double" << std::endl; //silinecek bu baştakiler.
	char c = static_cast<char>(d);
	if (std::isnan(d) || std::isinf(d) || d < CHAR_MIN || d > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (std::isnan(d) || std::isinf(d) || d > (double)INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << d << std::endl;
}

/*
isnan() fonksiyonu, bir ondalıklı sayının NaN (Not a Number) olup olmadığını kontrol eder.
NaN değeri, bir matematik işleminin sonucu olarak tanımlanamayan veya hesaplanamayan bir değerdir.
Örneğin, sıfıra bölme işlemi sonucu NaN değeri elde edilebilir. isnan() fonksiyonu, bir ondalıklı
sayının NaN değeri olup olmadığını kontrol eder ve true veya false değeri döndürür.
*/

/* isinf() fonksiyonu ise, bir ondalıklı sayının sonsuz (infinity) olup olmadığını kontrol eder.
Sonsuz değer, bir matematik işleminin sonucu olarak elde edilebilir.
Örneğin, bir sayı pozitif sınırsız değere bölündüğünde, sonuç sonsuz olacaktır.
isinf() fonksiyonu, bir ondalıklı sayının sınırsız değer olup olmadığını kontrol eder
ve true veya false değeri döndürür. */
void	printFloat(float f)
{
	std::cout << "float" << std::endl; //silinecek

	char c = static_cast<char>(f);
	if (std::isnan(f) || std::isinf(f) || f < CHAR_MIN || f > CHAR_MAX)
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (std::isnan(f) || std::isinf(f) || f > (float)INT_MAX || f < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	printInt(long i)
{
	std::cout << "int" << std::endl; //silinecek

	char c = static_cast<char>(i);
	if (i < CHAR_MIN || i > CHAR_MAX) //CHAR_MIN ve CHAR_MAX, char veri türünün taşıyabileceği en küçük ve en büyük sayısal değerlerde olup olmadığı kontrol edilir.  <climits> 
		std::cout << "char: impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

/* static_cast operatörü, bir veri türünden başka
bir veri türüne doğrudan dönüştürme yapar. Bu operatör,
genellikle derleme zamanında gerçekleşen güvenli tür
dönüşümlerinde kullanılır. */
void	printChar(char c)
{
	std::cout << "char" << std::endl; //silinecek
	
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl; //buna da hiçbir zaman girmiyor sanırım.
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

/* strtol, strtof, strtod fonksiyonları, sırasıyla int, float ve double'a
dönüştürmeye çalışarak giriş değerinin türünü belirleme işlevleri.
getType fonksiyonunda bu fonksiyonlardaki dönüşümler başarılı olursa
kullandığımız endptr string'in sonunu işaret eder ve başarılı dönüşümün
türünü döndürürüz getType'tan */

/* std::strtol fonksiyonu, verilen string'i, nümerik bir değere dönüştürür.
Bu dönüştürme işlemi sırasında, fonksiyonun işleminin durmasını sağlayacak bir
karaktere kadar olan kısmı dönüştürür. Dönüştürülemeyen kısımlar,
fonksiyonun ikinci argümanı olan char *endptr'de tutulur. */

/* std::strtol fonksiyonu, input string'inin tamamını dönüştürmeye çalışır.
Eğer başarıyla tamamını dönüştürebilirse, endptr değişkeni, input string'inin
sonuna işaret eder. Bu durumda, errno değişkeni sıfırlanmış olacaktır.
Bu koşullar sağlanıyorsa, fonksiyon int veri tipine dönüştürülebilecek
bir girdi aldığı anlaşılır ve "int" string'i döndürülür.
Bunun yanı sıra, eğer std::strtol fonksiyonu başarısız olursa,
errno değişkeni set edilir. Örneğin, girdi olarak "abc" string'i verilirse,
dönüştürme işlemi başarısız olacak ve errno değişkeni EINVAL (invalid argument)
değerini alacaktır. 
*/

/* strtol fonksiyonunun üçüncü parametresi sayısal dönüşümde kullanılan sayı sistemi bazını belirtir.
0 verilmesi durumunda, strtol fonksiyonu input değişkeninin sayı sistemini otomatik olarak belirler.
input değişkeni 0 ile başlıyorsa ve sonraki karakter 'x' veya 'X' ise sayı sistemi 16'ya, '0' ile başlıyorsa
sayı sistemi 8'e, aksi takdirde sayı sistemi 10'a göre belirlenir. */

/* if (endptr == input.c_str() + input.length() && errno == 0)
ilk koşul, endptrnin dönüştürme işlemi sonrasında input'un sonuna kadar
gelip gelmediğini kontrol eder. Eğer endptr'nin konumu input'un sonuna eşitse,
bu dönüştürmenin bütün karakterler tarafından kullanıldığı anlamına gelir.
Yani, girdinin tamamı başarılı bir şekilde dönüştürülmüştür.

İkinci koşul, errno değerini kontrol eder. errno, C standard kütüphanesinin
bir parçasıdır ve hata durumlarını rapor etmek için kullanılır.*/

/*Eğer errno'nun değeri sıfırsa, bu da işlemin başarılı olduğunu gösterir.
strtol fonksiyonu, dönüştürme işlemi sırasında herhangi bir hata oluşursa
errno değişkenine uygun bir hata kodu atar. Bu kodlar C dilinde önceden tanımlanmıştır
ve hata ayıklama sürecinde yardımcı olurlar.*/

std::string	ScalarConverter::getType(const std::string input)
{
	if (input.length() == 0)
		return "empty";
	else if (input.length() == 1 && !std::isdigit(input[0]))
		return "char";
	else
	{
		char* endptr = NULL;
		errno = 0;
		std::cout << "strtol:"<< std::strtol(input.c_str(), &endptr, 0) << std::endl;
		//if (*endptr == '\0') şeklinde neden kontrol etmiyoruz?
		//errno kontrolüne gerek var mı kesinlikle?
		std::cout << "endptr:" << endptr << std::endl;
		std::cout << "errno:" << errno << std::endl;
		if (endptr == input.c_str() + input.length() && errno == 0) {
			return "int";
		}
		else
		{
			endptr = NULL;
			errno = 0;
			std::cout << "strtoDDDD:"<< std::strtod(input.c_str(), &endptr) << std::endl;
			//if (*endptr == '\0') şeklinde neden kontrol etmiyoruz?
			//errno kontrolüne gerek var mı kesinlikle?
			std::cout << "endptr:" << endptr << std::endl;
			std::cout << "errno:" << errno << std::endl;
			std::strtod(input.c_str(), &endptr);
			if (endptr == input.c_str() + input.length() && errno == 0) {
				return "double";
			}
			else
			{
				endptr = NULL;
				errno = 0;

				std::strtof(input.c_str(), &endptr);
				std::cout << "strtoFFF:"<< std::strtof(input.c_str(), &endptr) << std::endl;
				//if (*endptr == '\0') şeklinde neden kontrol etmiyoruz?
				//errno kontrolüne gerek var mı kesinlikle?
				std::cout << "endptr:" << endptr << std::endl;
				std::cout << "errno:" << errno << std::endl;
				// ((endptr == input.c_str() + input.length()) || bu koşulu silmeliyiz bence...
				if (((endptr == input.c_str() + input.length()) || (endptr[0] == 'f' && endptr[1] == 0)) && errno == 0) {
				return "float";
				}
				else {
					return "unknown";
				}
			}
		}
	}
}

void ScalarConverter::convert(const std::string input)
{	
	std::string type = getType(input); // You have to first detect the type of the literal passed as parameter 
	if (type == "char") {
		char c = input[0];
		printChar(c);
	} else if (type == "int") {
		long l = std::atol(input.c_str()); //strtol tercih edilmeme sebebi? //atol vs. strtol farkı?
		printInt(l);
	} else if (type == "float") {
		float f = std::strtof(input.c_str(), NULL);
		printFloat(f);
	} else if (type == "double") {
		double d = std::strtod(input.c_str(), NULL);
		printDouble(d);
	} else
	{
		if (errno) //bu ne zaman çalışır?
			std::perror("Error");
		else
			std::cout << "type: " + type << std::endl;
	} 
}