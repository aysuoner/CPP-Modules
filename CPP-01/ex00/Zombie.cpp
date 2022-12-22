#include "Zombie.hpp"

/*Constructor
constructarda bu tanımlama default tnaımlama değildir.
default () şekilinde olmalıdır
o yüzden ben parametre oalrak kendim bir string verdiysem
constuctor'a içine daha sonra Class tüeünde bir değişken oluşturacağım zaman da
bunlara uygun parametreler ve değişken typeları vermeliyim.
ben arguman gerektiren (burada olduğu gibi...) bir constructor oluşturursam;
compiler benim için bir constructor sentezlemez.
Nesleri oluşturma sorumluluğunu ben üstlenmiş oldum*/
Zombie::Zombie(string str)
{
	cout << "\001\033[1m\033[37m\002\nConstructor called for " << str << " zombie...\001\033[0;0m\002" <<endl;
	cout << "\001\033[1m\033[37m\002Object(zombie) is being created...\001\033[0;0m\002" << endl;
	Name = str;
	cout << "\033[1m\033[32m" <<Name << ": created\033[0m\n" << endl;

}

// Deconstructor
Zombie::~Zombie()
{
	cout << "\001\033[1m\033[37m\002\nDeconstructor func called for " << Name << " zombie...\001\033[0;0m\002" <<endl;
	cout << "\001\033[1m\033[37m\002Object(zombie) is being destroyed...\001\033[0;0m\002" << endl;
	cout << "\033\033[31m" << Name << ": destroyed!\033[0m\n" << endl;
}

// Public Methods
void	Zombie::announce(void)
{
	cout << "\033[1m\033[35m" << Name << ": BraiiiiiiinnnzzzZ...\033[0m" << endl;
}

void	delete_obj(Zombie *obj, string name)
{
	cout << "\033[1m\033[37m\ndelete_obj func -->> deallocate memory for the object on the HEAP\033[0m" << endl;
	cout << "\033[1m\033[31m" << name << ": deallocated!\033[0m\n" << endl;
	delete obj;
}
