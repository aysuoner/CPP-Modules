/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:05:40 by aoner             #+#    #+#             */
/*   Updated: 2023/02/03 12:05:59 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//constructors
WrongAnimal::WrongAnimal(void)
{
	this->type = "Default Wrong-Animal";
	std::cout << ">	Wrong-Animal Class default constructor has been called " << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &old_obj)
{
	*this = old_obj;
	std::cout << ">	Wrong-Animal Class copy constructor has been called" << std::endl;
}

//destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << ">	Wrong-Animal Class destructor has been called" << std::endl;
	
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &old_obj)
{
	if (this != &old_obj)
	{
		this->setType(old_obj.getType());
	}
	std::cout << ">	Wrong-Animal Class copy assignment operator has been called" << std::endl;
	return *this;
}

//getters-setters

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

std::string WrongAnimal::getType(void)const
{
	return(this->type);
}


//public methods
void	WrongAnimal::makeSound(void)const
{
	std::cout << "***WrongAnimal SoundS***" << std::endl;
}
