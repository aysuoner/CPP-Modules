#include <iostream>

using std:: cout;
using std:: endl;

class megap
{
	public:
	char upper_case(int c)
	{
		if (c >= 97 && c <= 122)
			c -= 32;
		return(c);
	}
};

int main(int argc, char **argv)
{
	int i;
	int k;
	megap cmep;

	i = 1;
	if (argc >=  2)
	{
		while (argv[i])
		{
			k = 0;
			while (argv[i][k])
			{
				cout << cmep.upper_case(argv[i][k]);
				k++;
			}
			i++;
		}
	}

	else if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	cout << endl;
}