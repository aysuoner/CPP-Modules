#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string _ideas [100];
public:
	//constructors
	Brain();
	Brain(const Brain &old_obj);

	//overloaded operator
	Brain &operator=(const Brain &old_obj);

	//destructor
	~Brain();
};

#endif