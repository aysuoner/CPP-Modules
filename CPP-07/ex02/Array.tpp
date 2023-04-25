/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:53:56 by aoner             #+#    #+#             */
/*   Updated: 2023/04/25 20:16:23 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void)
{
	_size = 0;
	_arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_arr = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other)
{
	_size = other._size;
	_arr = new T[_size];
    for (unsigned int i(0); i < _size; i++){
        _arr[i] = other._arr[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& other)
	{
        if (this != &other)
		{
            delete[] _arr;
            _size = other._size;
            _arr = new T[_size];
            for (unsigned int i = 0; i < _size; i++){
                _arr[i] = other._arr[i];
			}
        }
        return *this;
    }

template <typename T>
T& Array<T>::operator[](unsigned int i) const
{
    if ( i >= _size )
        throw OutOfBoundsException();
    return _arr[i];
}
template <typename T>
unsigned int  Array<T>::size(void) const
{
	return _size;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _arr;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index is out of bounds";
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& arr)
{
    for (unsigned int i(0); i < arr.size(); i++)
        out << arr[i] << " ";
    return out;
};
