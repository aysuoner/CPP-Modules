#include <stack>
#include <iostream>
#include <string>


/*LIFO prensibine göre çalışır.
Yani son giren ilk çıkar mantığıyla.
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