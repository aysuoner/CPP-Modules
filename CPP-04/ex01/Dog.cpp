/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:55:29 by aoner             #+#    #+#             */
/*   Updated: 2023/02/04 19:43:07 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Dog.hpp"

//constructors
Dog::Dog(void): Animal()
{
	this->type = "Dog";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Dog Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << ">	Dog Class default constructor has been called" << std::endl;
}

Dog::Dog(const Dog &old_obj)
{
	this->_brain = new Brain();
    *this->_brain = *(old_obj._brain);
	this->setType(this->getType());
	std::cout << ">	Dog Class copy constuctor has been called" << std::endl;
}

//destructors
Dog::~Dog()
{
	delete this->_brain;
	std::cout << ">	Dog Class destructor has been called" << std::endl;
}

//overloaded operators
Dog	&Dog::operator=(const Dog &old_obj)
{
	if(this != &old_obj)
	{
		delete this->_brain;
		this->_brain = new Brain;
		if (this->_brain == NULL)
		{
			perror("Dog Brain allocation failed"); //cerr ile yaz!!!
			std::cerr << "Exiting the process now." << std::endl;
			exit(1);
		}
		*this->_brain = *(old_obj._brain);
		this->setType(old_obj.getType());
	}
	std::cout << ">	Dog Class copy assignment operator has been called" << std::endl;
	return *this;
}

void	Dog::makeSound(void)const
{
	std::cout << this->getType() << ":	HHHHirrrrrgggg" << std::endl;
}