#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	//constructors
	Animal(void);
	Animal(const Animal &old_obj);

	//destructors
	virtual	~Animal();

	//overloaded operator
	Animal	&operator=(const Animal &old_obj);

	//setter
	void	setType(const std::string _type);

	//getter
	std::string	getType(void) const;

	//public methods
	virtual void	makeSound(void)const = 0;
};


#endif