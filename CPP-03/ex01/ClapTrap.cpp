/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:34:50 by aoner             #+#    #+#             */
/*   Updated: 2023/01/29 14:26:51 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << ">	ClapTrap default constructor has been called!" << std::endl;
	this->_name			= "-defaultname-";
	this->_hitPoints	= 10;
	this->_energyPoints = 10;
	this->_attackDamage	= 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << ">	Destructor has been called!";
	std::cout << "... so ClapTrap " << this->_name << " is dead!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << ">	ClapTrap constructor with an argument has been called!" << std::endl;
	this->_name			= name;
	this->_hitPoints	= 10;
	this->_energyPoints	= 10;
	this->_attackDamage	= 0;
}

/* copy const ve copy assigment operator fonksiyonlarını
get ve set fonksiyonları ile çağırmak doğru bir şey mi? */
ClapTrap::ClapTrap(const ClapTrap &old_obj)
{
	std::cout << ">	ClapTrap copy constructor has been called!" << std::endl;
	this->setName(old_obj.getName());
	this->setHitPoints(old_obj.getHitPoints());
	this->setEnergyPoints(old_obj.getEnergyPoints());
	this->setAttackDamage(old_obj.getAttackDamage());

	//OR
	//*this = old_ obj;		????
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &old_obj)
{
	/* if(this != &ogr) kontrolü, copy assignment operator fonksiyonunda,
	kendine atama yapılmamasını sağlamak için yapılır. Yani, eğer this pointer'ı
	ve ogr parametresi aynı nesneyi gösteriyorsa, yani kendine atama yapılıyorsa,
	hiçbir işlem yapılmamasını sağlar. Bu durumda, program hata vermeden çalışmaya
	devam eder ve performansı arttırır */
	std::cout << ">	ClapTrap copy assignment operator has been called!" << std::endl;
	if(this != &old_obj)
	{
		this->setName(old_obj.getName());
		this->setHitPoints(old_obj.getHitPoints());
		this->setEnergyPoints(old_obj.getEnergyPoints());
		this->setAttackDamage(old_obj.getAttackDamage());
	}
	return *this;
}

//Setters
void	ClapTrap::setName(std::string _name)
{
	this->_name = _name;
}

void	ClapTrap::setHitPoints(unsigned int _hitPoints)
{
	this->_hitPoints = _hitPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int _energyPoints)
{
	this->_energyPoints = _energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int _attackDamage)
{
	this->_attackDamage = _attackDamage;
}

//Getters
std::string ClapTrap::getName(void) const
{
	return(this->_name);
}

unsigned int	ClapTrap::getHitPoints(void)const
{
	return(this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return(this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return(this->_attackDamage);
}

//Public Methods
void	ClapTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		this->setAttackDamage(1);
		std::cout << ">	ClapTrap " << this->getName()
					<< " attacks " << target
					<< " causing " << this->getAttackDamage()
					<< " points of damage! (Updated HitPoints: "
					<< this->getHitPoints() << " EnergyPoints: "
					<< getEnergyPoints() << ")" << std::endl;
	}
	else
		std::cout << "!!!	ClapTrap " << this->getName()
				<< " is too weak to attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "!!!	ClapTrap " << this->getName()
				<< " is already dead. RIP " << this->getName() << std::endl;
	}
	else if (amount >= this->getHitPoints())
	{
		this->setHitPoints(0);
		std::cout << "!!!	ClapTrap " << this->getName()
				<< " is dead just now. RIP " << this->getName() << std::endl;
	}
	else
	{
		this->setHitPoints(getHitPoints() - amount);
		std::cout << ">	ClapTrap " << this->getName()
				<< " takes " << amount << " points of damage (Updated HitPoints: "
				<< this->getHitPoints() << " EnergyPoints: "
				<< getEnergyPoints() << ")" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "!!!	ClapTrap " << this->getName()
				<< " is already dead so it does not need to heal" << std::endl;
	}
	else if (this->getEnergyPoints() <= 0)
	{
			std::cout << "!!!	ClapTrap " << this->getName()
				<< " is too weak to repairing" << std::endl;	
	}
	else
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		this->setHitPoints(this->getHitPoints() + amount);
		std::cout << ">	ClapTrap " << this->getName()
				<< " got repaired by " << amount
				<< " points (Updated HitPoints: " << this->getHitPoints()
				<< " EnergyPoints: " << getEnergyPoints() << ")" << std::endl;
	}
}