/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:09:04 by aoner             #+#    #+#             */
/*   Updated: 2023/01/24 22:33:29 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_num = 0;
}

Fixed::Fixed(const Fixed &other)
{
	 *this = other;
}

Fixed::Fixed(const int a) //gelen 10 integer değerini 8bit sola kaydırıyoruz 2560 oluyor.
{
	fixed_num = (a << this->fract_bit); /*Shifting the bits of a to the left by the number of bits
										specified by the fract_bit member of the object.*/
}

Fixed::Fixed(const float a) //42,42 sayısını 256 ile çarptık roundf onu 10860 olarak verdi bize;
{
    fixed_num = std::roundf(a *( 1 << fract_bit)); //Rounding the number a to the nearest integer.
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->fixed_num = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
;
}

int Fixed::getRawBits() const
{
	return fixed_num;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_num = raw;
}

float Fixed::toFloat() const
{
	return ((fixed_num / (float)(1 << fract_bit)));
}

int Fixed::toInt() const
{
	/* Converting the fixed point value to a floating point value. */
	return ((fixed_num / (float)(1 << fract_bit)));
}

std::ostream &operator<<(std::ostream& out, const Fixed &other)
{
	out << other.toFloat();
    return out;
}

//------------------ arithmetic operators ------------------//
/* //other olarak giden yani parametre olarak +'nın sağındakidir.
+'nın solundaki bu operatorü çağırandır.
this-> dediğimizde solundakinin değerlerini çağırmış oluruz.*/
/* Fixed	Fixed::operator+(const Fixed &other) const
!!!parametre olarak gönderilen const other class'ının değişkenlerinin değiştirilmesini engelliyor.
dışarıdaki const ise bu fonksiyonu çağıran this->class'ının değişkenlerinin değiştirilmesi engelliyor.
o yüzden ikisini de kullanmak önemli!!!!*/
Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	res;

	res = this->toFloat() + other.toFloat(); 
	return res;
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	res;

	res = this->toFloat() - other.toFloat();
	return res;
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	res;

	res = this->toFloat() * other.toFloat();
	return res;
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	res;

	res = this->toFloat() / other.toFloat();
	return res;
}

//------------------ comparison operators ------------------//
//github örneğinde tofloat() ile karşılaştırmak yerine getrawbits ile karşılaştırıyor?
//benim yaptığım yanlış mı getrawbits mi olmalı????
bool	Fixed::operator==(const Fixed &other) const
{
	if (this->toFloat() == other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (this->toFloat() != other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator<(const Fixed &other) const
{
	if (this->toFloat() < other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator>(const Fixed &other) const
{
	if (this->toFloat() > other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (this->toFloat() <= other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (this->toFloat() >= other.toFloat())
		return true;
	else
		return false;
}

//------------------ Increment/Decrement operators ------------------//
Fixed	Fixed::operator++(int)
{
	Fixed	old;

	old = *this;
	this->fixed_num++;
	return old;
}

Fixed	Fixed::operator--(int)
{
	Fixed	old;

	old = *this;
	this->fixed_num--;
	return old;
}

//prefixlerde neden & Fixed::..kullanılıyor
//ben kullanmadan yaptın yanlış mı?
Fixed	Fixed::operator++(void)
{
	Fixed	&newf = *this;
	this->fixed_num++;
	return newf;
}

Fixed	Fixed::operator--(void)
{
	Fixed	&newf = *this;

	this->fixed_num--;
	return newf;
}


 Fixed	&Fixed::min(Fixed &a, Fixed&b)
 {
	if (a < b)
		return a;
	return b;
 }

 /* A static member function min that takes as parameters two references
 to constant fixed-point numbers, and returns a reference to the smallest one. */
const Fixed 	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}