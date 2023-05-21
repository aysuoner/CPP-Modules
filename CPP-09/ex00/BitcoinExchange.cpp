/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:22:12 by aoner             #+#    #+#             */
/*   Updated: 2023/05/21 17:46:22 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* std::ifstream(Input file stream class)
C++ standart kütüphanesinde yer alan bir sınıftır.
Bu sınıf, bir dosya okuma işlemi gerçekleştirmek için kullanılır.
Dosyayı açmak için open() fonksiyonu kullanılır.
Dosya açıldıktan sonra, is_open() fonksiyonu ile dosyanın açılıp
açılmadığı kontrol edilir. Dosya işlemi tamamlandıktan sonra,
close() fonksiyonu ile dosya kapatılır.
std::ifstream, ayrıca get(), getline(), read() gibi işlevlerle
birlikte kullanılabilir. Bu işlevler, dosyadan veri okumak için kullanılır.

!!!!!!Eğer dosya açıldıysa, std::ifstream file nesnesi, dosyayı temsil eden bir
giriş akışı nesnesine dönüşür. Dosyayı temsil eden bir giriş akışı nesnesine dönüşmek,
dosyadan veri okuyabilmek için bir araç sağlamaktır.!!!!

std::ifstream nesnesi, bir dosyanın verilerini okumak için kullanılan bir giriş akışı nesnesidir.
Dosya açıldıktan sonra, std::ifstream nesnesi, dosyadan veri okumak, dosyayı sıfırlamak
ve dosyayı kapamak için kullanılır. Bu nesne, dosyadan veri okumak ve diğer işlemleri
gerçekleştirmek için kullanılabilir.*/

/* std::ifstream ve std::ofstream, C++ standart kütüphanesinde yer alan sınıflardır.
std::ifstream, dosya okuma işlemleri için kullanılırken,
std::ofstream dosya yazma işlemleri için kullanılır.
Her iki sınıf da fstream sınıfından türetilir ve open(),
close() ve is_open() gibi fonksiyonlarla birlikte kullanılır.

std::ifstream sınıfı, getline(), get() ve read() gibi işlevlerle birlikte kullanılarak,
dosyadan veri okunabilir.
Ayrıca, std::ofstream sınıfı, put(), write() ve flush() gibi
işlevlerle birlikte kullanılarak, dosyaya veri yazılabilir.

C++ standart kütüphanesi, fstream sınıfı aracılığıyla hem dosya okuma hem de dosya yazma işlemlerini destekler.
Bu sınıf, std::ifstream ve std::ofstream sınıflarının özelliklerini birleştirir ve hem okuma hem de yazma
işlemlerini tek bir nesne aracılığıyla yapmayı mümkün kılar.
*/

/*
file.open(fileName.c_str(), std::ios::in);
ikinci parametre ios_base isim alanı içinde tanımlı olan önceden tanımlanmış sembolik sabitler kullanılarak oluşturulabilir.
Dosyanın okuma modunda açılmasını gösterir. Eğer open fonksiyonunu tek parametreli kullanırsak zaten default olarak okuma modunda açar.
std::ios::in, std::ios::out(yazma mod) std::ios::app(sona ekleme mod) std::ios::trunc(dosya açılırken içeriği siler)
*/

bool	file_check(const std::string fileName, std::ifstream &file)
{
    file.open(fileName.c_str(), std::ios::in);
    if (!file.is_open())
    {
        std::cerr << "Error: File cannot be opened" << std::endl;
		file.close();
        return false;
    }
    return true;
}

bool	fill_input(std::ifstream &file, std::vector<std::pair<std::string, std::string> > &_vInput)
{
	size_t		pos;
	std::string	line;
	std::string	val;
	std::string	date;

	while (std::getline(file, line))
	{
		pos = line.find(" | ");
		if (pos != std::string::npos)
		{
        	date = line.substr(0, pos);
        	val = line.substr(pos+3);
        	_vInput.push_back(std::make_pair(date, val));
        }
		else
			_vInput.push_back(std::make_pair("-1", "-1")); //sadece bir parse girildiyse. "Bad input" hatası alsın.
	}
	if (_vInput.size() == 0) //dosyanın içi boşsa. file is empty hatası alır.
		return false;
	file.close();
	return true;
}

void	mark_invalid_input(std::vector<std::pair<std::string, std::string> > &_v)
{
	int i = 0;
	for (std::vector<std::pair<std::string, std::string> >::const_iterator it = _v.begin(); it != _v.end(); ++it)
	{
		if (is_valid_date(it->first) == false || is_valid_value(it->second) == "false")
		{
			_v[i].first = "-1";
			_v[i].second = "-1";
		}
		i++;
	}
}

bool	is_valid_date(const std::string& date)
{
	char *endptr = NULL;
	// Date format should be "yyyy-mm-dd"
    if (date.size() != 10) {
        return false;
    }
    // Check year
    int year = std::strtol(date.substr(0, 4).c_str(), &endptr, 10);
    if (*endptr != '\0' || year < 2009 || year > 9999 || date[4] != '-') {
        return false;
    }
    // Check month
	endptr = NULL;
    int month = std::strtol(date.substr(5, 2).c_str(), &endptr, 10);
    if (*endptr != '\0' || month < 1 || month > 12 || date[7] != '-' ) {
        return false;
    }
    // Check day
	endptr = NULL;
    int day = std::strtol(date.substr(8, 2).c_str(), &endptr, 10);
    if (*endptr != '\0' || day < 1 || day > 31 || (year == 2009 && month == 01 && day == 01)) {
        return false;
    }
    // Check if day is valid for the given month
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    if (month == 2) {
        int max_day = 28;
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            max_day = 29;
        }
        if (day > max_day) {
            return false;
        }
    }
    return true;
}

std::string	is_valid_value(const std::string& value)
{
	unsigned int i = 0;

	for(; i < value.length() && value[i] != ' '; i++);

	if (value.empty() || i != value.length()) {
		return "false";
	}
	else
	{
		char* endptr = NULL;
		long l = std::strtol(value.c_str(), &endptr, 0);
		if (*endptr == '\0')
		{
			if (l > 1000 || l < 0)
				return "false";
			return "int";
		}
		else
		{
			endptr = NULL;
			float f = std::strtof(value.c_str(), &endptr);
			if (*endptr == '\0' || (endptr[0] == 'f' && endptr[1] == 0))
			{
				if (f > 1000 || f < 0)
					return "false";
				return "float";
			}
			else
			{
				return "false";
			}
		}
	}
}

void	fill_data_base(std::ifstream &file, std::vector<std::pair<std::string, double> > &_vData)
{
	std::string	date;
	std::string	val;
	std::string	line;
	size_t		pos;
	double		btc;

	while(std::getline(file, line))
	{
		pos = line.find(",");
		if (pos != std::string::npos)
		{
        	date = line.substr(0, pos);
        	val = line.substr(pos+1);
			btc = strtod(val.c_str(), NULL);
        	_vData.push_back(std::make_pair(date, btc));
        }
	}
	file.close();
}

void	print_and_handle(const std::vector<std::pair<std::string, std::string> > &_v, const std::vector<std::pair<std::string, double> > &_vData)
{
	double  multiple;
	int		indx; 
	
	for (std::vector<std::pair<std::string, std::string> >::const_iterator it = _v.begin(); it != _v.end(); ++it)
	{
		if (it->first == "-1" || it->second == "-1")
		{
			std::cout << "Error: bad input" << std::endl;	
		}
		else
		{
			indx = find_same_date_indx(it->first, _vData);
			multiple = strtod(it->second.c_str(), NULL) * _vData[indx].second;
			std::cout << it->first << " => " << it->second << " = " << multiple << std::endl;
		}
	}
}

int	find_same_date_indx(const std::string& targetDate, const std::vector<std::pair<std::string, double> >& _vData)
{
    int	n = _vData.size();
    int	left = 0;
	int	right = n-1;
	int	mid;
    while (left <= right)
	{
        mid = (left + right) / 2;
        if (_vData[mid].first == targetDate)
		{
            return mid;
        }
		else if (_vData[mid].first < targetDate)
		{
            left = mid + 1;
        }
		else
		{
            right = mid - 1;
        }
    }
    // If the target date is not found, return the index of the nearest lower date
    if (right < 0) {
        return -1; // There is no lower date, return an invalid index
    } else {
        return right;
    }
}
