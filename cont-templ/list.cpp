#include <list>
#include <iostream>
#include <vector>


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
    std::list<int> l4(l2.begin(), l2.end()); //vectorlerde istediğimiz indx'e indis operator

}