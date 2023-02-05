#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain *_brain;
public:
	//constructors
	Dog(void);
	Dog(const Dog &old_obj);

	//Destructor
	~Dog();

	//overloaded oprators
	Dog	&operator=(const Dog &old_obj);

	//Public Methods
	void	makeSound(void)const;
};

#endif
