/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:58:36 by aoner             #+#    #+#             */
/*   Updated: 2023/02/05 15:37:55 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << ">	Brain class default constructor has been called" << std::endl;
}

/* 
old_obj'nin ideas arrayindeki içerikleri This->ideas'ına kopyaalar.
*this = old_obj tarzı kullanımı burada yapmıyoruz çünkü bu kullanım
copy constructor'ın tekrar tekrar çalışmasına neden olur.
For döngüsü ise tek tek atamaya yardımcı olur.
lenght ve assign fonklar::::
lenght->	i index'indeki ideas içeriğinin boş olup olmadığını kontrol ediyorum
böylelikle sadece dolu olan stringleri this'ideas'a eklemiş oluyorum.
assign->	this->ideas[i] = old_obj.ideas[i] kullanımını daha doğru halidir.
çünkü assign kullanımı atama yapılacak olan stringin boyutunun değişme durumunda
yani bellekte kaplayacağı alanın boyutunun değişmesi durumunda assign fonksiyonu dizenin boyutunu otomatik olarak ayarlar böylece hem dizideki veriyi korur hem de 
programın beklenmedik şekilde çalışmasının önüne geçilir. */
Brain::Brain(const Brain &old_obj)
{
	std::cout << ">	Brain class copy constructor has been called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (old_obj._ideas[i].length() > 0)
			this->_ideas[i].assign(old_obj._ideas[i]);
	}
}

/*
ilk if ifadesi, kaynak ve hedef nesnelerin aynı olup olmadığını kontrol eder.
Aynıysa, herhangi bir değişiklik yapmadan nesnenin kendisini döndürür.
Buna self-assignment koruması denir ve  bir nesnenin kendisine atandığı durumlarda
beklenmedik davranışları önlemeye yardımcı olur. 
 */
Brain &Brain::operator=(const Brain &old_obj)
{
	std::cout << ">	Brain class copy assignment operator has been called" << std::endl;
	if (this == &old_obj)
		return *this;
	for (int i = 0; i < 100; i++)
	{
		if (old_obj._ideas[i].length() > 0)
			this->_ideas[i].assign(old_obj._ideas[i]);
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << ">	Brain class deconstructor has been called" << std::endl;
}