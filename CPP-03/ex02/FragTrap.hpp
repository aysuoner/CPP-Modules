#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap(void);
	~FragTrap();
	FragTrap(std::string _name);
	FragTrap(const FragTrap &old_obj);
	FragTrap	&operator=(const FragTrap &old_obj);
	void highFivesGuys(void);
};

#endif