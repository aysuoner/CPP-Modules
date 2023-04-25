/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:01:28 by aoner             #+#    #+#             */
/*   Updated: 2023/04/25 13:11:39 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

/*template <typename T> ifadesi, bir fonksiyon şablonu tanımlarken kullanıldığında,
fonksiyonun her çağrılışında farklı bir türle özelleştirilebileceği anlamına gelir.
Bu sayede, aynı işlemi farklı türlerdeki veriler üzerinde uygulamak için
tek bir fonksiyon şablonu yazılabilir.
Bu ifade, şablonun T türünde bir parametre aldığını belirtir.
T, kodun farklı yerlerinde bir tür adı olarak kullanılabilir. */

/*
Bir std::string'in büyüklüğü veya küçüklüğü,
Unicode karakterlerinin sayısal değerlerine dayanır.
std::string tipindeki iki string'in karşılaştırılması,
std::string sınıfı tarafından sağlanan operator< fonksiyonu
kullanılarak gerçekleştirilir.
Bu fonksiyon, Unicode karakterlerinin sayısal değerlerine
göre karşılaştırma yapar ve sonuç olarak iki string'in büyüklüğünü
veya küçüklüğünü belirler.*/

/* ::swap() fonksiyonunun parametre olarak alacağı veri türü belirtilmediği için,
programın çağrıldığı yerde tür belirleme (type deduction) işlemi yapılır.
Bunun yerine, ::swap<int>() şeklinde tür belirtilirse,
derleyici bu türü kullanarak fonksiyonu derleyecektir.*/

/* C++98 standartlarına göre, template fonksiyonlarının isimleri global namespace'te (::) tanımlanır.
Ancak, aynı isimde bir fonksiyon veya nesne bulunması durumunda, bu belirsizliğe neden olabilir.
Bu durumda, :: kullanarak global namespace içindeki fonksiyonu çağırarak bu belirsizliği gidermek mümkündür.
Örneğin, bir standart kütüphane fonksiyonu olan min ile aynı isimde bir template fonksiyonu tanımlarsanız,
çağırmak için ::min kullanarak global namespace içindeki min fonksiyonunu çağırmalısınız.
Aynı şekilde, bir sınıf veya başka bir namespace içinde tanımlanmış bir fonksiyonun
ismini kullanırken de :: kullanarak global namespace'deki fonksiyonu çağırmak gerekebilir. */

int main( void )
{
	std::cout << "TEST INT" << std::endl;
	int a = 2;
	int b = 3;
	::swap<int>(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << "\nTEST STRING " << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap<std::string>(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "\nTEST FLOAT" << std::endl;
	float a1 = 3.46;
	float b1 = 2;
	::swap<float>(a1,b1);
	std::cout << "a = " << a1 << ", b = " << b1 << std::endl;
	::swap(a1,b1);
	std::cout << "a = " << a1 << ", b = " << b1 << std::endl;

	double a2 = 3.14;
	double b2 = 2.71828;
	std::cout << "\nTEST DOUBLE" << std::endl;
	::swap<double>(a2,b2);
	std::cout << "a = " << a2 << ", b = " << b2 << std::endl;
	std::cout << "min( a, b ) = " << ::min( a2, b2 ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a2, b2 ) << std::endl;
	return 0;
}
