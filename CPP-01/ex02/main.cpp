#include <iostream>

using std:: cout;
using std:: endl;
using std:: string;

int main()
{
	string	str = "HI THIS IS BRAIN";
	string 	*stringPTR;
	string	&stringREF = str;

	stringPTR = &str;
	cout << "string variable ADD:	" << &str << endl;
	cout << "stringPTR ADD:		" << stringPTR << endl;
	cout << "stringREF ADD:		" << &stringREF << endl;
	cout << endl;
	cout << "string:		" << str << endl;
	cout << "stringPTR:	" << *stringPTR << endl;
	cout << "stringREF:	" << stringREF << endl;
	return(0);
}