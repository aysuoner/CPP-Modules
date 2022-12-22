#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon _weapon;
		string _name;
	public:
		void	attack(string name, Weapon _type);
};

#endif