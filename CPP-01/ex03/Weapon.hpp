#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

using std:: cout;
using std:: string;
using std:: endl;

class Weapon
{
	private:
		string	_type;
	public:
		Weapon();
		~Weapon();
		string	getType() const;
		void	setType(string type);
};

#endif