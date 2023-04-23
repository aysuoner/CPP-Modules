/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:59:23 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/23 23:49:49 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int	random;

	random = rand() % 3;
	if (random == 0) {
		std::cout << "creating A" << std::endl;
		return (new A);
	}else if (random == 1) {
		std::cout << "creating B" << std::endl;
		return (new B);
	}else if (random == 2) {
		std::cout << "creating C" << std::endl;
		return (new C);
	}else
		return (NULL);
}


/* Dinamik örtüşme, bir alt sınıfın bir üst sınıf işaretçisiyle
işaret edildiği durumlarda, alt sınıfın türünü belirlemek için kullanılır.  */

/* Pointer fonksiyonları genellikle nullptr olabilen işaretçilerle çalışırken,
referans fonksiyonları genellikle nullptr olmayan referanslarla çalışır.
Bu nedenle, referans fonksiyonları dynamic_cast işlemleri için try-catch
bloklarını kullanmak daha uygun olabilir.*/

/* İşaretçiler, bellekteki bir nesneye veya bir fonksiyona işaret eden bir değişken türüdür.
Referanslar ise, bir nesneye takma ad (alias) vermek için kullanılan bir değişken türüdür.
Bir işaretçi, bir nesneyi göstermeyi veya göstermemeyi seçebilir.
Bu nedenle, bir işaretçi nullptr olabilir, yani hiçbir nesneye işaret etmeyebilir.
Dolayısıyla, bir işaretçi fonksiyonu genellikle işaretçinin nullptr olup olmadığını
kontrol etmek için if-else bloklarını kullanır.
Öte yandan, bir referans, her zaman bir nesneye bağlıdır ve nullptr olamaz.
Bu nedenle, bir referans fonksiyonu nullptr kontrolü için if-else blokları
yerine try-catch bloklarını kullanabilir. Bu try-catch blokları,
referansın istenmeyen bir nesneye veya türe sahip olması durumunda
yönetilemeyen hataları yakalamak için kullanılabilir. */
void identify(Base* p)
{
	if (dynamic_cast<A* >(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B* >(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C* >(p) != nullptr)
		std::cout << "C" << std::endl;
}

/*dönüştürme işlemi başarısız olur ve std::bad_cast istisnası fırlatılır. */
void	identify(Base &p)
{
	Base	ptr;
	try
	{
		ptr = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::exception& e) {}
	try
	{
		ptr = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(std::exception& e) {}
	try
	{
		ptr = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(std::exception& e) {}
}

int main()
{
	Base	*base;

	srand(time(NULL));

	base = generate();
	std::cout << "res: ";
	identify(base);
	delete base;

	usleep(1756);
	
	base = generate();
	std::cout << "res: ";
	identify(*base);
	delete base;
	
	return 0;
}

