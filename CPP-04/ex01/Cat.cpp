/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:55:33 by aoner             #+#    #+#             */
/*   Updated: 2023/02/05 15:14:32 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//constructors
Cat::Cat(void): Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Cat Brain allocation failed"); //cerr ile yaz!!!
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << ">	Cat Class default constructor has been called " << std::endl;
}

/* kopyalanacak Cat nesnesi için yeni bir Brain nesnesi oluşturulması ve
other.brain adresine işaret eden Brain nesnesinin içeriğinin kopyalanması açıkça yapılır.
Böylece, yeni oluşan Cat nesnesinin kendi benzersiz bir Brain nesnesi olduğu görülür ve
bu, beklenen davranış olabilir.
FAKAT;
*this = other şeklindeki kopyalanacak nesnenin atama işlemini içeren copy constructor,
other nesnesinin tüm içeriğini yeni oluşan Cat nesnesine kopyalar, Brain işaretçisi dahil.
Bu durumda, yeni Cat nesnesi ile ilgili Brain nesnesi, orijinal Cat nesnesi ile aynı Brain nesnesini paylaşır.
Bu beklenen davranış olmayabilir.
*/
Cat::Cat(const Cat &old_obj)
{
	this->_brain = new Brain();
    *this->_brain = *(old_obj._brain);
	this->setType(this->getType());
	std::cout << ">	Cat Class copy constructor has been called" << std::endl;
}

//destructor
Cat::~Cat()
{
	delete this->_brain;
	std::cout << ">	Cat Class default destructor has been called" << std::endl;
}

Cat	&Cat::operator=(const Cat &old_obj)
{
	if (this != &old_obj)
	{
		delete this->_brain;
		this->_brain = new Brain;
		if (this->_brain == NULL)
		{
			perror("Cat Brain allocation failed"); //cerr ile yaz!!!
			std::cerr << "Exiting the process now." << std::endl;
			exit(1);
		}
		*this->_brain = *(old_obj._brain);//cat nesnesini kopyaladığımzda, onunla ilişkili Brain nesnesi de kopyalanacaktır. Her nesnenin kendi benzersiz Brain nesnesi ve kendi "fikirleri" ile olduğundan emin oluruz.!!!
		this->setType(old_obj.getType());
	}
	std::cout << ">	Cat Class copy assignment operator has been called";
	return *this;
}

void	Cat::makeSound(void)const
{
	std::cout << this->getType() << ":	MirRRrRR" << std::endl;
}