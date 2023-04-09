#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>

template <class T>
class Array
{
private:
	T				*_arr;
	unsigned int	_size;

public:
    Array(void) : _size(0)
	{
		_arr = new T[0]; 
	};
    Array(unsigned int n)
	{
		_size = n;
		_arr = new T[n];
	};
    Array(const Array& rhs)
	{
		_size = rhs._size;
		_arr = new T[_size];
        for (unsigned int i(0); i < _size; i++){
            _arr[i] = rhs._arr[i];
		}
    };

    Array& operator=(const Array& rhs)
	{
        if (this != &rhs)
		{
            delete[] _arr;
            _size = rhs._size;
            _arr = new T[_size];
            for (unsigned int i(0); i < _size; i++){
                _arr[i] = rhs._arr[i];
			}
        }
        return *this;
    }

    T& operator[](unsigned int i) const
	{
        if ( i >= _size )
            throw OutOfBoundsException();
        return _arr[i];
    }

    unsigned int  size(void) const
	{
		return _size;
	}

    ~Array(void)
	{
		delete[] _arr;
	}

    class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw(){
				return "Index is out of bounds";
			}
    };
};

template < typename T >
std::ostream& operator<<(std::ostream& out, const Array<T>& arr)
{
    for (unsigned int i(0); i < arr.size(); i++)
        out << arr[i] << " ";
    return out;
};

#endif