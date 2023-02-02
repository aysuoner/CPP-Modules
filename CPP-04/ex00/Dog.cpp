/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:55:29 by aoner             #+#    #+#             */
/*   Updated: 2023/02/02 17:14:00 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Dog.hpp"

//constructors
Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << ">	Dog Class default constructor has been called" << std::endl;
}

Dog::Dog(const Dog &old_obj)
{
	std::cout << ">	Dog Class copy constuctor has been called" << std::endl;
	*this = old_obj;
}

//destructors
Dog::~Dog()
{
	std::cout << ">	Dog Class destructor has been called" << std::endl;
}

//overloaded operators
Dog	&Dog::operator=(const Dog &old_obj)
{
	if(this != &old_obj)
	{
		this->setType(old_obj.getType());
	}
	std::cout << ">	Dog Class copy assignment operator has been called" << std::endl;
	return *this;
}

void	Dog::makeSound(void)const
{
	std::cout << this->getType() << ":	HHHHirrrrrgggg" << std::endl;
}