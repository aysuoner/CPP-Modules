#include <iostream>
#include <vector>

template <typename T>
void    printv(std::vector<T> &v)
{
    //std::vector<int>::iterator i = v.begin(); //tek int için geçerli
    typename std::vector<T>::iterator i = v.begin(); //bu ise tipini işlem sırasında belirleyecektir typename olduğu için
    while (i != v.end())
        std::cout << *i++ << " ";
    std::cout << std::endl;
}


int main()
{
    //default;
    std::vector<int> v;

    //size'ı 2 olan, 10 değerlerine sahip olan int arrayi
    std::vector<int> v1(4, 10);
    std::cout << "V1    " << v1[0] << " "<< v1[1]<< std::endl;
    std::cout << std::endl;

    //array size = 5 diyorum ama içine değer ataması yapmadım.
    std::vector<int> v2(5);

    //v2'nin 0. elemanından v2'nin 1. elemanına kadar kopyala
    std::vector<int> v3(&v1[0], &v1[2]);
    std::cout << "V3    "<< v3[0] << " "<< v3[1]<< std::endl;
    std::cout << std::endl;

    //v3teki değerleri v5'e kopyaladım
    std::vector<int> v5(v3);
    std::cout << "V5    " << v5[0] << " "<< v5[1]<< std::endl;
    std::cout << std::endl;

    /*burada v6 vektorünü ilk başta array size'ını 3 ile başlattım
    ve hepsinin içi 0 ile dolu. Daha sonra push.back() yaptığımda dynamic olduğu için
    size3'ten sonrasına pushbaclkeri ekliyor ve pushbackler sonrası size 9 oluyor!!!!!1*/
    std::vector<int> v6 (3);
    v6.push_back(12);
    v6.push_back(34);
    v6.push_back(23);
    v6.push_back(24);
    v6.push_back(25);
    v6.push_back(26);
    std::cout << "v6size: "<< v6.size() << std::endl;
    v6.pop_back(); //sondaki değeri sildim. 26'yı göremeyeceğiz. size'da -1 azaldı
    std::cout << "NEWv6size: "<< v6.size() << std::endl;
    std::cout << std::endl;

    for(int i = 0; i < v6.size(); i++)
    {
        std::cout << v6[i] << " ";
    }
    std::cout << std::endl;
    //insert member func ile vector içindeki istediğim pozisyondaki değeri değiştirdim
    //iterator kullanımı...
    std::cout << "v6indx3: "<<v6[3] << std::endl;
    std::vector<int>::iterator it = v6.begin() + 3;
    v6.insert(it, 125);
    std::cout << "new v6indx3: "<<v6[3] << std::endl;

    //iterator kullanarak vector içini yazdırmak...
    std::cout << "\niterator kullanarak vector içini yazdırmak..." << std::endl;
    std::vector<int>::iterator it1 = v6.begin();
    while(it1 != v6.end())
    {
        std::cout << *it1 << " ";
        it1++;
    }
    std::cout << std::endl;

    //iteratorlü fonksiyon tanımlamak
    std::cout << "\niteratorlü fonksiyon tanımlamak ve çağırmak..." << std::endl;
    printv(v6);

    std::cout << "\nITERATORRRRSSSSS" << std::endl;
    std::vector<std::string> v8;
    std::cout << "isempty: "<< v8.empty() << std::endl;
    v8.insert(v8.begin(), "aysu");
    v8.insert(v8.begin(), "ecole");
    v8.insert(v8.begin(), "42"); //buranın çıktısına dikkattt artık başta 42 var...
    v8.push_back("ist");
    v8.push_back("berlin");
    std::cout << "isempty: " << v8.empty() << std::endl;
    printv(v8);

}