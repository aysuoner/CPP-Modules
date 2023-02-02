/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:06:38 by aoner             #+#    #+#             */
/*   Updated: 2023/02/02 18:36:16 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//constructor
WrongCat::WrongCat(void)
{
	this->type = "Wrong-Cat";
	std::cout << ">	Wrong-Cat Class default constructor has been called " << std::endl;
}

WrongCat::WrongCat(const WrongCat &old_obj)
{
	*this = old_obj;
	std::cout << ">	Wrong-Cat copy constructor has been called " << std::endl;
}

//destructor
WrongCat::~WrongCat()
{
	std::cout << ">	Wrong-Cat destructor has been called " << std::endl;
}

//operator overloaded

WrongCat &WrongCat::operator=(const WrongCat &old_obj)
{
	if (this != &old_obj)
	{
		this->setType(old_obj.getType());
	}
	std::cout << ">	Wrong-Cat Class copy assignment operator has been called" << std::endl;
	return *this;
}

void	WrongCat::makeSound(void)const
{
	std::cout << this->getType() << "	Wrong-meeeeeuuuvvv " << std::endl;
}