#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std:: getline;

class	Zombie
{
	private:
		string	_name;
	public:
		Zombie();
		~Zombie();
		void	announce(void);
		void	set_name(string name);
};

Zombie	*zombieHorde(int N, string name);

#endif