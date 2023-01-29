/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:59:48 by aoner             #+#    #+#             */
/*   Updated: 2023/01/29 15:58:25 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << ">	ScavTrap default constructor has been called!" << std::endl;
	this->_name			= "-defaultname-";
	this->_hitPoints	= 100;
	this->_energyPoints = 50;
	this->_attackDamage	= 20;
	this->_guardingGate = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << ">	Destructor has been called!";
	std::cout << "... so ScavTrap " << this->_name << " is dead!" << std::endl;
}

ScavTrap::ScavTrap(std::string _name): ClapTrap(_name)
{
	std::cout << ">	ScavTrap constructor with an argument has been called!" << std::endl;
	this->_name			= _name;
	this->_hitPoints	= 100;
	this->_energyPoints	= 50;
	this->_attackDamage	= 20;
	this->_guardingGate = false;
}

ScavTrap::ScavTrap(const ScavTrap &old_obj): ClapTrap(old_obj)
{
	std::cout << ">	ClapTrap copy constructor has been called!" << std::endl;
	this->_guardingGate = old_obj._guardingGate;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &old_obj)
{
	std::cout << ">	ScavTrap copy assignment operator has been called!" << std::endl;
	if(this != &old_obj)
	{
		this->setName(old_obj.getName());
		this->setHitPoints(old_obj.getHitPoints());
		this->setEnergyPoints(old_obj.getEnergyPoints());
		this->setAttackDamage(old_obj.getAttackDamage());
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		this->setAttackDamage(1);
		std::cout << ">	ScavTrap " << this->getName()
					<< " attacks " << target
					<< " causing " << this->getAttackDamage()
					<< " points of damage! (Updated HitPoints: "
					<< this->getHitPoints() << " EnergyPoints: "
					<< getEnergyPoints() << ")" << std::endl;
	}
	else
		std::cout << "!!!	ScavTrap " << this->getName()
				<< " is too weak to attack!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_guardingGate == false)
	{
		this->_guardingGate = true;
		std::cout << ">	ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << ">	ScavTrap " << this->_name << " is already guarding the gate.\033[0m" << std::endl;
}