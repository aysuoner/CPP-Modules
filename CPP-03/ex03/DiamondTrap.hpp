#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	//constructors
	DiamondTrap(void);
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap &old_obj);

	//destructors
	virtual		~DiamondTrap();

	//Overloaded Operator
	DiamondTrap	&operator=(const DiamondTrap &old_obj);

	//Public Methods
	void		attack(const std::string &target);
	void		whoAmI(void);

};


#endif