#ifndef EASYFIND_HPP	
#define EASYFIND_HPP

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <list>

class NotFoundException: public std::exception
{
	public:
			virtual const char *what() const throw()
			{
				return ("Not found");
			}
};

/* typename T::iterator şeklinde belirtilen fonksiyonun geri dönüş
değeri, T türünün hangi konteyner türü olduğundan bağımsızdır.
Çünkü birçok konteyner türü, ::iterator türüne sahip olduğu için,
typename T::iterator türü belirli bir türü ifade etmek yerine,
bir tür ailesini ifade eder. Bu nedenle, çağıran kod tarafından
geri dönüş değeri türü belirtilmesine gerek yoktur ve typename
T::iterator türü doğru şekilde tanımlanmışsa, fonksiyon kullanıldığı
konteyner türü ne olursa olsun doğru şekilde çalışacaktır. Bu nedenle
easyfind fonksiyonuna bir tür belirtilmediği takdirde, container
parametresinin hangi türde olduğu belirsiz kalacaktır. Bu belirsizlik,
çağıran kod tarafından tür belirtilmedikçe, hata veya yanlış
sonuçlara neden olabilir.*/

/* std::find fonksiyonu, verilen değeri içeren ilk öğenin işaretçisini
döndürür. Bu işaretçi, konteynerin sonunu gösteren işaretçiyle eşitse,
değer bulunamamıştır. Örneğin, easyfind fonksiyonu, STL vector, list
veya set gibi birçok farklı konteyner türü için çalışabilir.
Ancak, kullanıcı tarafından tür belirtilmediğinde, container
parametresinin türü belirsiz kalacaktır. Bu durumda, bir std::vector
kullanıcı olarak düşünebiliriz. Ancak, container parametresinin türü
belirtilmediği için, easyfind fonksiyonu, çağrıldığı türün begin()
ve end() fonksiyonlarını çağırmaya çalışırken bir hata verebilir veya
yanlış sonuçlar döndürebilir. Örneğin, eğer container parametresi
aslında bir std::list ise, std::vector için optimize edilmiş
algoritmayı kullanmaya çalışarak hatalı sonuçlar üretebilir.
Bu nedenle, easyfind fonksiyonunun kullanılacağı türün açıkça
belirtilmesi önemlidir.*/

template< typename T>
typename T::iterator easyfind(T &src, int i)
{
	typename T::iterator	it_ptr;

	it_ptr = find(src.begin(), src.end(), i);
	/*iterator conteynırın sonunu gösteren
	işaretçi ile eşitse değer bulunamamış demektir.*/
	if (it_ptr == src.end())
	{
		throw (NotFoundException());
	}
	return (it_ptr);
}

#endif