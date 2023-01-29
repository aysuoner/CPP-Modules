#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap:public ClapTrap
{
private:
	bool	_guardingGate;
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap &old_obj);
	ScavTrap	&operator=(const ScavTrap &old_obj);

	void	attack(const std::string& target);
	void	guardGate(void);
};

#endif