#include "Zombie.hpp"

/*Bu tanım bir zombi yaratır, adlandırır ve
fonksiyon dışında kullanabilmeniz için geri döndürür.
so you can use it outside of the function.
Bu fonksiyon sayesinde ben OBJEME HEAP'te bir alan tahsis edeceğim.
new operatörü sayesinde heapte alan tahsisi yapacağım...
bu fonksiyon objeleri fonksiyon dışında kullanmamı sağlar.
çünkü burada heap'te yarattığım objemi return ediyorum.
bu fonksiyon heapte yarattığım objeye dolaylı erişim sağlaymak için kullanılacaktır */
Zombie *newZombie(string name)
{
	cout << "\033[1m\033[37mnewZombie func -->> allocates memory ON THE HEAP for an object.\033[0m" << endl;
	Zombie *heap= new Zombie(name); //new pointer döndürür.
	heap->announce();
	return (heap);
	/*new operatörü sayesinde heap'te nesne oluşturdum.
	heap'te oluşturduğum nesneye dönüş değeri sayesinde
	dolaylı olarak erişim sağlayaibldim.*/
}
