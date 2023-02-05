/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:44:55 by aoner             #+#    #+#             */
/*   Updated: 2023/02/05 17:23:22 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "--------------- Animal ---------------" << std::endl;

	//const Animal* meta = new Animal(); //testing
	const Animal* meta;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "J Type: " << j->getType() << " " << std::endl;
    std::cout << "I Type: " << i->getType() << " " << std::endl;
	meta = j;
	meta->makeSound();
    i->makeSound();
}
