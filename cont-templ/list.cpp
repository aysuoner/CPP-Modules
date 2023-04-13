#include <list>
#include <iostream>
#include <vector>

template <typename T>
void    printv(std::list<T> &v)
{
    //std::vector<int>::iterator i = v.begin(); //tek int için geçerli
    typename std::list<T>::iterator i = v.begin(); //bu ise tipini işlem sırasında belirleyecektir typename olduğu için
    while (i != v.end())
        std::cout << *i++ << " ";
    std::cout << std::endl;
}


/*list: vectorleri eklenecek eleman sayısının belirli olduğu durumlarda
kullanmak daha mantıklıyken listleri eklenecek eleman sayısının belirsiz
olduğu durumlarda kullanmak daha uygundur.
vectorler ile aynı kurucu metodlara sahiptir. merge ve remove ise kendine has metodlardır.
MERGE iki listeyi birleştirmeye yarar(ama uc uca eklemek değil de karışık bir ekleme yapar.)
vectorlerdeki erase bir pos verdiğimizde o posdaki değeri siliyordu.
liste has olan REMOVE(value) ise verdiğimiz değeri listenin neresinde görürse siliyor.
SPLICE(pos, object); bu listeyi(object) şu pozisyondan itibaren(pos) birleştir.
UNIQUE(); listedeki elemanlarda tekrarlanan elemanları teke indirir.


*/
int main()
{
    std::list<int> l1;
    std::list<int> l2(5, 42);
    std::list<int> l3(10);
	l2.push_back(12);
	l2.push_back(12);
	l2.push_back(12);
    std::list<int> l4(l2.begin(), l2.end()); //vectorlerde istediğimiz indx'e indis operator
	printv(l2);
	l2.remove(12);
	std::cout << "ls2 print: ";
	printv(l2);

	//splice
    std::list<int> l5;
	l5.push_back(1);
	l5.push_back(10);
	l5.push_back(9);
	l5.push_back(8);
	l5.push_back(5);
	std::cout << "ls5 print: ";
	printv(l5);
	std::cout << "ls2 print: ";
	l2.splice(l2.begin() ,l5);
	printv(l2);
	std::cout << "ls5 print: ";
	printv(l5);
	std::cout << "ls4 print: ";
	printv(l4);


	//merge
	l2.merge(l4);
	std::cout << "ls2 print: ";
	printv(l2);
	std::cout << "ls4 print: ";
	printv(l4);

	l2.unique();
	std::cout << "ls2 print: ";
	printv(l2);
}