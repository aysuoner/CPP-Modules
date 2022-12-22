#include <iostream>

using std:: string;
using std:: cout;
using std:: endl;

class megap
{
	private:
		char a;
	public:
		void set(char);
		char get();
};

void megap::set(char c)
{
	a = c;
	if (a >= 97 && a <= 122)
		a -= 32;
}

char megap::get()
{
	return(a);
}

int	main(int argc, char **argv)
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
				cmep.set(argv[i][k]);
				cout << cmep.get();
				k++;
			}
			i++;
		}
	}

	else if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	cout << endl;
}