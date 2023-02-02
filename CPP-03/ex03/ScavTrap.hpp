#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
private:
	bool	_guardingGate;
public:
	//Constructors
	ScavTrap();
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap &old_obj);

	//Destructors
	~ScavTrap();

	//Overloaded Operators
	ScavTrap	&operator=(const ScavTrap &old_obj);

	//Public Methods
	void		attack(const std::string& target);
	void		guardGate(void);
};

#endif