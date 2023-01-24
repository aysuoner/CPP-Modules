/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:09:04 by aoner             #+#    #+#             */
/*   Updated: 2023/01/24 15:21:27 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed()
{
	fixed_num = 0;
}

//Copy constructor
Fixed::Fixed(const Fixed &other)
{
	 *this = other;
}

//Constructor overload for int;
Fixed::Fixed(const int a) //gelen 10 integer değerini 8bit sola kaydırıyoruz 2560 oluyor.
{
	fixed_num = (a << this->fract_bit); /*Shifting the bits of a to the left by the number of bits
										specified by the fract_bit member of the object.*/
}

//Constructor overload for float;
//float value to be converted to fixed point
Fixed::Fixed(const float a) //42,42 sayısını 256 ile çarptık roundf onu 10860 olarak verdi bize;
{
    fixed_num = std::roundf(a *( 1 << fract_bit)); //Rounding the number a to the nearest integer.
}

//Copy assigment
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

//getters
int Fixed::getRawBits() const
{
	return fixed_num;
}

//setters
void Fixed::setRawBits(int const raw)
{
	this->fixed_num = raw;
}

//fixed point değeri floating point değerine dönüştürür.
float Fixed::toFloat() const
{
	return ((fixed_num / (float)(1 << fract_bit)));
}

//fixed point'i integer'a dönüştürür.
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
Fixed	Fixed::operator+(const Fixed &other)
{
	Fixed	res;

	res = this->toFloat() + other.toFloat(); 
	return res;
}

Fixed	Fixed::operator-(const Fixed &other)
{
	Fixed	res;
	
	std::cout << this->toFloat() << std::endl;
	std::cout << other.toFloat() << std::endl;
	res = this->toFloat() - other.toFloat();
	return res;
}


//------------------ arithmetic operators ------------------//
Fixed	Fixed::operator*(const Fixed &other)
{
	Fixed res;

	res = this->toFloat() * other.toFloat();
	return res;
}

Fixed	Fixed::operator/(const Fixed &other)
{
	Fixed	res;

	res = this->toFloat() / other.toFloat();
	return res;
}


//------------------ comparison operators ------------------//
bool	Fixed::operator==(const Fixed &other)
{
	if (this->toFloat() == other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator!=(const Fixed &other)
{
	if (this->toFloat() != other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator<(const Fixed &other)
{
	if (this->toFloat() < other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator>(const Fixed &other)
{
	if (this->toFloat() > other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator<=(const Fixed &other)
{
	if (this->toFloat() <= other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator>=(const Fixed &other)
{
	if (this->toFloat() >= other.toFloat())
		return true;
	else
		return false;
}




/* //------------------ Increment/Decrement operators ------------------//

Fixed	&Fixed::operator++(void) //arttır ve artmış halini döndür
{
	++this->fixed_num;
        return *this; // return new value by reference
}


Fixed   Fixed::operator++(int)
{
    Fixed old = *this; // copy old value
	operator++();  // prefix increment
	return old;    // return old value
}

Fixed	&Fixed::operator--(void)
{
	--this->fixed_num;
        return *this; // return new value by reference
}

Fixed Fixed::operator--( int )
{
    Fixed old = *this; // copy old value
    operator--();  // prefix decrement
    return old;    // return old value
} */
