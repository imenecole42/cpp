#ifndef SERIALIZER
#define SERIALIZER
#include <iostream>
#include <stdint.h>
#include "data.hpp"
class  Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);
	public:
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};
#endif
