#include <iostream>

using std:: cout;
using std:: endl;

int main(int argc, char **argv)
{
	int i;
	int k;

	i = 1;
	if (argc >=  2)
	{
		while (argv[i])
		{
			k = 0;
			while (argv[i][k])
			{
				if (argv[i][k] >= 97 && argv[i][k] <= 122)
					argv[i][k] -= 32;
				cout << argv[i][k];
				k++;
			}
			i++;
		}
	}

	else if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	cout << endl;
}