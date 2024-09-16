#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <stdexcept>
template <typename T>
class Array
{
	public:
		Array<T>();
		Array<T>(unsigned int n);
		~Array<T>();
		Array<T>(const Array<T> &cpy);
		Array<T> &operator=(const Array<T> &cpy);
		unsigned int getSize() const;
		T& operator[](unsigned int index);
	private:
		T* val;  // Tableau d'éléments de type T
    	unsigned int size;  // Taille du tableau

};
# include "Array.tpp"
#endif