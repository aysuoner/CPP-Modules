#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:
public:
	//constructors
	WrongCat(void);
	WrongCat(const WrongCat &old_obj);
	//destructor
	~WrongCat();
	//overloaded operators
	WrongCat &operator=(const WrongCat &old_obj);
	//public methods
	void	makeSound(void)const;
};

#endif