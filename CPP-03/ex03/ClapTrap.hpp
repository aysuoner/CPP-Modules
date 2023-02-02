#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string 	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;
public:
	//Constructors
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &old_obj);

	//Destructors
	virtual			~ClapTrap();

	// Overloaded Operators
	ClapTrap		&operator=(const ClapTrap &old);

	//Setter
	void			setName(std::string _name);
	void			setHitPoints(unsigned int _hitPoints);
	void			setEnergyPoints(const unsigned int _energyPoints);
	void			setAttackDamage(const unsigned int _attackDamage);

	//Getter
	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;

	//Public Methods
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};

#endif