#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

/* , void (*func)(T&) ifadesinde, func işlev işaretçisi,
T& türünden tek bir parametreye sahip olan herhangi bir işlevi gösterebilir.
Bu parametrenin ismi, işlev işaretçisinin kullanıldığı yerdeki isimden farklı olabilir
ve herhangi bir isim vermek zorunlu değildir. */
template <typename T>
void iter(T *arr, int len, void (*func)(T &))
{
	for(int i=0; i<len; i++)
	{
        func(arr[i]);
    }
}

template <typename T>
void print(T &val)
{
    std::cout << val << " ";
}

#endif