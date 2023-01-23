/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:09:04 by aoner             #+#    #+#             */
/*   Updated: 2023/01/23 19:30:11 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_num = 0;
}

//Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	//fixed_num = other.getRawBits();
	 *this = other;
}

//Constructor overload for int;
Fixed::Fixed(const int a) //gelen 10 integer değerini 8bit sola kaydırıyoruz 2560 oluyor.
{
	std::cout << "Int constructor called" << std::endl;
	fixed_num = (a << this->fract_bit); /*Shifting the bits of a to the left by the number of bits
										specified by the fract_bit member of the object.*/
}

//Constructor overload for float;
//float value to be converted to fixed point
Fixed::Fixed(const float a) //42,42 sayısını 256 ile çarptık roundf onu 10860 olarak verdi bize;
{
	std::cout << "Float constructor called" << std::endl;
    fixed_num = std::roundf(a *( 1 << fract_bit)); //Rounding the number a to the nearest integer.
}

//Copy assigment
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed_num = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
