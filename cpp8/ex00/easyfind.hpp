#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
template <typename T>
//data c mon containers
typename T::iterator  Easyfind( T & data,int val)
{
	    typename T::iterator it = data.begin();
		typename T::iterator end = data.end();
		while(it != end)
		{
			if(*it==val)
			{
				return it;
			}
			++it;
		}
		throw std::runtime_error("Element not found");
		
}
#endif
