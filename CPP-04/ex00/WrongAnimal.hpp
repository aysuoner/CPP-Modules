#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	//constructors
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &old_obj);

	//destructors
	virtual ~WrongAnimal();

	//overloadled operator
	WrongAnimal	&operator=(const WrongAnimal &old_obj);

	//getter-setter
	void		setType(std::string type);
	std::string	getType(void)const;

	//public methods
	virtual void	makeSound(void)const;
};


#endif