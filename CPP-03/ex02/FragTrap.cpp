/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:53:05 by aoner             #+#    #+#             */
/*   Updated: 2023/01/31 14:35:20 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << ">	FragTrap default constructor has been called" << std::endl;
	this->_name = "default_name";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap()
{	
	std::cout << ">	Destructor has been called!";
	std::cout << "... so FragTrap " << this->_name << " is dead!" << std::endl;
}

FragTrap::FragTrap(std::string _name): ClapTrap(_name)
{
	std::cout << ">	FragTrap constructor with an argument has been called!" << std::endl;
	this->_name = _name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &old_obj): ClapTrap(old_obj)
{
	std::cout << ">	FragTrap copy constructor has been called!" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &old_obj)
{
	std::cout << ">	FragTrap copy assignment operator has been called!" << std::endl;
	if(this != &old_obj)
	{
		this->setName(old_obj.getName());
		this->setHitPoints(old_obj.getHitPoints());
		this->setEnergyPoints(old_obj.getEnergyPoints());
		this->setAttackDamage(old_obj.getAttackDamage());
	}
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << ">	FragTrap " << this->_name << " highfiveeeee!" << std::endl;
}
