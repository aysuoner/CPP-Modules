#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
		~Serializer();
	private:
		Serializer();
		Serializer(Serializer const &);
		Serializer &operator=(Serializer const &);
};

#endif