/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:53:57 by aoner             #+#    #+#             */
/*   Updated: 2023/02/02 17:19:39 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

//constructors
Animal::Animal(void)
{
	this->type = "default-animal";
	std::cout << ">	Animal Class default constructor has been called " << std::endl;
}

Animal::Animal(const Animal &old_obj)
{
	*this = old_obj;
	std::cout << ">	Animal Class copy constructor has been called" << std::endl;
}

//destructor 
Animal::~Animal()
{	
	std::cout << ">	Animal Class destructor has been called" << std::endl;
}

//overloaded operator
Animal	&Animal::operator=(const Animal &old_obj)
{
	if (this != &old_obj)
	{
		this->setType(old_obj.getType());
	}
	std::cout << ">	Animal Class copy assignment operator has been called" << std::endl;
	return *this;
}

//setter and getters
void	Animal::setType(const std::string _type)
{
	this->type = _type;
}

std::string	Animal::getType(void) const
{
	return(this->type);
}

//public methods
void		Animal::makeSound(void)const
{
	std::cout << ">	Animal default sounds" << std::endl;
}