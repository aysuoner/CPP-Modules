#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <list>
# include <vector>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		
		MutantStack() : std::stack<T>(){}
		
		MutantStack(const MutantStack &other) : std::stack<T>(other) {}

		MutantStack &operator=(const MutantStack &other)
		{
			std::stack<T>::operator=(other);
			return *this;
		}

		~MutantStack() {}

		iterator begin() {
			return std::stack<T>::c.begin(); 
		}
		iterator end() { 
			return std::stack<T>::c.end(); 
		}
};

#endif

/* stack bir container değil container adaptördür.
Container adaptörler: "Stack, queue, priority_queue" bunlar aslında
kendi başlarına bir container değillerdir.STL (Standard Template Library)
kütüphanesindeki önceden tanımlanmış veri yapılarını
(containerları) bir arayüz üzerinden kullanarak yeni veri
yapılarına dönüştürmeye olanak tanıyan bir araçlardır.
Container adaptorlar container değillerdir ve bu yüzden iterator sunmazlar.
Bu nedenle STL algoritmaları containers adaptorleri doğrudan çağıramaz.
containers adaptorleri yalnızca sunulan arayüz ile kullanabiliyoruz.
*/

/*  SequenceContainer: array, vector, forward_list, list, deque;
aynı tip verileri sıralı bir şekilde saklayan veri yapılarını ifade etmek için kullanılır.
 */

/* Template'in
1.param: Bu template T türünde ögeler alır.
2.param: T türündeki ögeler bu template'te deque veri yapısı şeklinde saklanır.

Template'in ikinci tür parametresi olan Container
stackteki öğeleri tutacak container'in türü. YANİ-->Stackte veriler veri yapısını biçiminde yani bir container biçimde
tutulmadıkları için ben MutantStack class'ımda Classin içindeki ögelerin artık bir 
container şeklinde tutulmasını istiyorum. O yüzden ikinci parametrede class'ımın içindeki
T türündeki öğelerin veri yapısı (container) türü deque<T> olsun diyorum.
Yani stackte tutulacak T türündeki ögeler
aslında "deque veri yapısı" şeklinde tutulacak diyorum...
Burada kullanılan C türünün STL‘in SequenceContainer
özelliklerini sağlaması ve aynı zamanda
back()
push_back()
pop_back() fonksiyonlarına sahip olması gerekiyor.
O yüzden bu özellikleri sağlayan list, vector, deque gibi
SequenceContainer çeşitleri stackteki ögeleri container
şeklinde tutmak için template'e verilen ikinci parametredir.
Stack'in kullanacağı container'i kendimiz belirlemek istersek
bu parametre için dilediğimiz container türünü seçebiliyoruz.
Aksi halde deque container'ını kullanmayı kabul etmiş oluyoruz
 */

/* stack, queue ve priority queue container adaptors denir.
bunlar STL container değillerdir teknik olarak. bir container'ı eleman olarak.
nonstatic data member olarak alırlar(stack.c - protected üye olarak tanımlanmıştır stack içinde)
ve eleman olarak aldıkları Container'ın arayüzünü adapte ederek bazı soyut veri yapılarının
implemantasyonunu gerçekleştirecek interface'e sahip olurlar.
 */
/* Bu kod, "std::stack" sınıf şablonunun "container_type" öğesinin "iterator" türüne "iterator"
adında bir takma ad (alias) oluşturur.typename" anahtar kelimesi burada,
"std::stack<T>::container_type::iterator" ifadesinin bir tür olduğunu belirtir.
Bu, "iterator" adını kullanarak, "std::stack" sınıf şablonunun içindeki
"container_type::iterator" türüne daha kolay erişim sağlar. */
/* 
typedef typename std::stack<T>::container_type::iterator iterator;
container_type: temel container'ın bir stack tarafından uyarlanmasını sağlayan bir tür. */
/* std::stack sınıfı, standart olarak std::deque sınıfını temel alır ve varsayılan olarak
std::deque kullanır. Bu nedenle, MutantStack sınıfı da Container tipi için varsayılan olarak
std::deque<T>'yi kullanabilir. */
