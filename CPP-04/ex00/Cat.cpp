/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:55:33 by aoner             #+#    #+#             */
/*   Updated: 2023/02/03 11:40:53 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//constructors
Cat::Cat(void): Animal()
{
	this->type = "Cat";
	std::cout << ">	Cat Class default constructor has been called " << std::endl;
}

Cat::Cat(const Cat &old_obj)
{
	*this = old_obj;
	std::cout << ">	Cat Class copy constructor has been called" << std::endl;
}

//destructor
Cat::~Cat()
{
	std::cout << ">	Cat Class default destructor has been called" << std::endl;
}

Cat	&Cat::operator=(const Cat &old_obj)
{
	if (this != &old_obj)
	{
		this->setType(old_obj.getType());
	}
	std::cout << ">	Cat Class copy assignment operator has been called";
	return *this;
}

void	Cat::makeSound(void)const
{
	std::cout << this->getType() << ":	MirRRrRR" << std::endl;
}