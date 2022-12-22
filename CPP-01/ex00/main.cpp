#include "Zombie.hpp"

/* alıştırmanın asıl amacı nedir?
Zombileri stack veya heap’e ayırmanın hangi durumda daha iyi olduğunu belirlemelisin!!!!
Artık onlara ihtiyacınız olmadığında zombiler yok edilmelidir
Yıkıcı, hata ayıklama amacıyla zombinin adını içeren bir mesaj yazdırmalıdır. */
int	main(void)
{
	Zombie	*heapzombie;
	string	name;

	name = "RANDOM";
	randomChump(name);
	name = "NEW";
	heapzombie = newZombie(name);
	delete_obj(heapzombie, name);
	return (0);
}