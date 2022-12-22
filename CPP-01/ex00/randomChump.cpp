#include "Zombie.hpp"

/*Bir zombi yaratır, onu adlandırır ve
zombi kendini duyurur(and the zombie announces itself)*/
void randomChump(string name)
{
	cout << "\033[1m\033[37m\nrandomChump func -->> allocates memory ON THE STACK for an object.\033[0m" << endl;
	Zombie stack = Zombie(name);
	stack.announce();
}