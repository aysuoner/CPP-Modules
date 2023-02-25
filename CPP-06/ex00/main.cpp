#include "Cast.hpp"

int main(int argc, char **argv)
{
	Cast cast;
	if (argc == 2)
	{
		cast.setChar(argv[1]);
		std::cout << "char:	" << cast.getChar() << std::endl;
		cast.setInt(argv[1]);
		std::cout << "Int:	" << cast.getInt() << std::endl;
	}
}






//-21474836447 dene bunu 















/* Önce parametre olarak geçirilen değişmezin türünü algılamanız,
dizeden gerçek türüne dönüştürmeniz ve ardından açıkça diğer
üç veri türüne dönüştürmeniz gerekir.
Bir dönüşüm herhangi bir anlam ifade etmiyorsa veya taşıyorsa,
kullanıcıya tür dönüştürmenin imkansız olduğunu bildirmek için
bir mesaj görüntüleyin.
Sayısal sınırları ve özel değerleri işlemek için
ihtiyacınız olan herhangi bir başlığı ekleyin.*/


