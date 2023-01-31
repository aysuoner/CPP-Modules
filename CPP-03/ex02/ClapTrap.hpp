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
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &old_obj);
	~ClapTrap();

	void			setName(std::string _name);
	void			setHitPoints(unsigned int _hitPoints);
	void			setEnergyPoints(const unsigned int _energyPoints);
	void			setAttackDamage(const unsigned int _attackDamage);
	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;


	ClapTrap	&operator=(const ClapTrap &old);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif