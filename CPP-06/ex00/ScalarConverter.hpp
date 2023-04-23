#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <climits> 
#include <cerrno>

/* ScalarConverter sınıfı statik bir sınıftır.
Bunu, sınıfın tanımlanmasında tüm üyelerinin static
olarak tanımlanması ve bir nesne oluşturulmadan sınıfın
fonksiyonlarının çağrılabilmesi ile anlayabiliriz.
Ayrıca sınıfın herhangi bir örneği olmadığı için constructor'ı
private olarak tanımlanmış.*/

/* C++dilinde bir sınıfı statik olarak tanımlayamazsınız. C# diline özgü bir tanımlamadır
aslında statik class... C++ dilinde ancak sınıfın tüm member değişken ve funclarını statik
olarak tanımlarsak sınıfın tüm değişkenleri artık bir nesneye bağımlı olmaz tüm sınıf için
ortak değerlere sahip olur.*/

/* STATIC CLASS!!! Bir sınıfın tüm üyeleri static hale getirildiğinde, statik sınıf haline gelir.
Ancak, bu durumda sınıftan bir örnek oluşturulması mümkün olmaz, çünkü tüm üyeler
statik hale gelir ve herhangi bir örnekleme ihtiyacı kalmaz. Bu nedenle, statik
sınıfların bir örneği oluşturulamaz. Statik sınıfların yalnızca 
statik üye fonksiyonlarını kullanarak işlemler yapabileceğini ve
örneklendirilemeyeceğini unutmayın.*/

/* STATIC MEMBER FUNC!!! Bir static üye fonksiyonu, sınıfının herhangi bir nesnesine veya
statik olmayan herhangi bir veri üyesine veya başka bir sınıfa erişemez."
bu örnekte de benden statik bir sınıf oluşturmam isteniyor. C++'ta static sınıf oluşturmak için
tüm member üyeleri static hale getirmem gereklidir. Ben tüm member funcları static hale getirdiğimde bu member funclar
bir nesneye erişemez duruma gelmiş olurlar. içinde this kullanamam. o halde static fonksiyonlarım nesnelere erişemediğine göre 
ve tüm fonksiyonlarım da statik olduğuna göre constructor vs. işlevsiz kalır. O yüzden bunları private alanda belirleyebilirim*/

/* Bir sınıfın tüm üyeleri static hale getirildiğinde, sınıf artık bir statik sınıf haline gelir ve örneklendirilemez.
Bu nedenle, bu sınıftan örnekler oluşturulamaz ve dolayısıyla constructor, copy constructor veya copy assignment
operator gibi örneklendirmeyle ilgili işlevlerin tanımlanması gerekli değildir. */

/* STATIC VARIABLE bir sınıfın private bölümünde tanımlanan bir static değişken, sınıfın tüm örnekleri tarafından paylaşılır.
Bu, sınıfın bir örneği tarafından değiştirildiğinde, değişiklik diğer örnekler tarafından da görüleceği anlamına gelir.
Static değişkenlerin bellekte sadece bir kopyası vardır ve ömrü programın ömrü kadardır.
Ayrıca, bir sınıfın static değişkeni herhangi bir örnek olmadan da kullanılabilir.*/

class ScalarConverter
{
	public:
		static void			convert(const std::string input);
		static std::string	getType(std::string input);

		~ScalarConverter();
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
};

#endif