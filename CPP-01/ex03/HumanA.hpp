#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon	_weapon;
		string	_name;
	public:
		void	attack(string name, Weapon _type);

};

#endif