#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
class Span
{
	public:
		Span();
		Span(unsigned int num);
		Span(const Span &cpy);
		Span & operator = (const Span &cpy);
		~Span();
		void bubbleSort(std::vector<int>& arr);
		void addNumber(unsigned int num);
		int shortestSpan();
		int longestSpan();
		void addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) ;
	private:
		unsigned int N;
		std::vector<int> val;

};
#endif