#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:
	//Constructors
	FragTrap(void);
	FragTrap(std::string _name);
	FragTrap(const FragTrap &old_obj);

	//Destructors
	~FragTrap();

	//Overloaded Operator
	FragTrap	&operator=(const FragTrap &old_obj);

	//Public Methods
	void		highFivesGuys(void);
};

#endif