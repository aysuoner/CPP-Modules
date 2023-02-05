#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain *_brain;
public:
	//constructor
	Cat(void);
	Cat(const Cat &old_obj);

	//destructor
	~Cat();

	//overloaded operator
	Cat &operator=(const Cat &old_obj);

	//public methods
	void	makeSound(void)const;
};



#endif