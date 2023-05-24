/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:59:41 by aoner             #+#    #+#             */
/*   Updated: 2023/05/24 22:09:05 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*std::stringstream bir C++ sınıf şablonudur ve <sstream> başlık dosyasında tanımlanmıştır.
Bu sınıf, akış işlemlerini gerçekleştirmek için kullanılır.
std::stringstream, std::istream ve std::ostream sınıflarından türetilmiştir, 
bu nedenle hem giriş hem de çıkış işlemlerini destekler. 
Bir std::stringstream nesnesi oluşturduğunuzda, bu nesne buffer olarak davranır ve içerisine veri yazılabilir veya okunabilir.
std::stringstream nesnesi oluşturmak, bir buffer ile ilişkili olan bir nesne yaratmak anlamına gelir.
Buffer, verilerin geçici olarak depolandığı bir alanı temsil eder.
std::stringstream nesnesi oluşturduğunuzda, bellekte bir alan ayrılır
ve bu alana karakterlerin geçici olarak depolanması için bir buffer oluşturulur.
std::stringstream nesnesi olan ss'yi oluşturur. Bu nesne, bir bellek tamponuna sahip olacaktır.
Bu tampon, örneğin metin verilerini depolamak için kullanılabilir.*/

/* std::stringstream nesnesi, bir bellek tamponu ve akış işlemlerini gerçekleştirebilen bir sınıf şablonudur.
Nesne oluşturulduğunda, bir bellek tamponu ayrılır ve bu tampon, akış işlemleri için bir ara bellek olarak kullanılır. */

int		RPN::count = 0;
float	RPN::val = 0;
float	RPN::first = 0;
float	RPN::second = 0;
std::string RPN::param = "";
std::stack<float> RPN::_sVal;
std::stack<char> RPN::_sOperant;

RPN::RPN() {}
RPN::~RPN() {}
RPN &RPN::operator=(const RPN &) {return *this; }
RPN::RPN(const RPN &) {}

/* önce onu dizgi akımı nesnesine dönüştürürüz.
Ardından, bir döngüde (her boşlukta durduğu için) bir çıkarma operatörü
kullanarak her kelimeyi sayarız. Son olarak, toplam kelime sayısının
değerini yazdırıyoruz. */
void	RPN::word_count(std::string param)
{
    std::stringstream ss; //or (param);
    std::string word;
	ss << param; //or ss.str(param) //stringstream tamponuna(dizi akışı nesnesine) veri atıyorum/ekliyorum.
	while (ss >> word)
        count++;
}

bool	RPN::fill_and_check_string(std::string* arr)
{
    std::stringstream ss(param);
    std::string word;
    for (int i = 0; i < count; i++)
	{
        ss >> arr[i];
		if (arr[i].length() != 1) {
				return(false);
		}
		else if (!std::isdigit(arr[i][0]) && arr[i][0] != '-' && arr[i][0] != '+' \
				&& arr[i][0] != '*' && arr[i][0] != '/')
		{
			return(false);
		}
	}
	return(true);
}

bool	RPN::polish_handle(std::string const *arr)
{
	int		i = 0;
	char	oper;

	//bunu ikiye böl;
	//bunu stringstream ile yapabilir misin dene?
	while(i < count)
	{
		if (isdigit(arr[i][0]))
		{
			val = atof(arr[i].c_str());
			_sVal.push(val);
		}
		else if (!isdigit(arr[i][0]) && _sVal.size() < 2)
		{
			//sorunun ne oldugunu spesifik goster.
			return (false);
		}
		else if (!isdigit(arr[i][0]))
		{
			_sOperant.push(arr[i][0]);
		}
		if (_sVal.size() >= 2 && _sOperant.size() >= 1)
		{
			oper = _sOperant.top();
			_sOperant.pop();
			second = _sVal.top();
			_sVal.pop();
			first = _sVal.top();
			_sVal.pop();
			switch (oper)
			{
				case addition :
					_sVal.push(first + second);
					break;
				case  division :
					_sVal.push(first / second);
					break;
				case subtraction :
					_sVal.push(first - second);
					break;
				case multiplication :
					_sVal.push(first * second);
					break;
			}
		}
		i++;
	}
	return (true);
}
