#include <stack>
#include <iostream>
#include <string>

/*LIFO prensibine göre çalışır.
Yani son giren ilk çıkar mantığıyla.
*/

/* stackler listelerin özelleştirlmiş bir halidir.
biz bir listeye baştan veya sondan eleman ekleyip aynı şekilde
bunları listeden çıkartabiliyorduk. stacklere her zaman baştan
eleman eklenir ve  baştan eleman çıkar. Stack veri yapısı elaman depolaman için değil
elemanların giriş sırasının önemli olduğu, göz önünde bulundurulması gereken durumlarda kullanılır.
stack kullanıyorsak her zaman son giren elemanla işlem yapıyoruz demektir.
*/

/* begin ve end medotları ile::: veri yapımızın bellek üzerinde hangi adreste başlayıp hangi adreste bittiğini almaya çalışıyoruz  pointer(iterator) üzerinden.
begin() metodu ile veri yapımızın başlangıç adresini alırken end() metodu ile  bellek üzerinde bittiği aderesi alırız.
*/


int main()
{
	std::stack<int> st1; //default const;
	st1.push(10);
	st1.push(20);
	st1.push(30);
	st1.push(40);
	std::cout << st1.top();
	return 0;

} 