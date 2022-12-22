#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

using std::	string;
using std:: endl;
using std:: cout;

class Zombie
{
	private:
		string Name;
	public:
		//Zombie(string str) : Name(str) {}; //aşağıdaki constuctors'ın diğer kullanımı.
		Zombie(string str); //constuctors;
		~Zombie(); //decontructors;
		void	announce(void);
};

Zombie	*newZombie(string name);
void	randomChump(string name);
void	delete_obj(Zombie *obj, string name);

#endif