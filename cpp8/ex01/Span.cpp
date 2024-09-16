#include "Span.hpp" 
Span::Span(){};
Span::Span(unsigned int num):N(num){
	val.reserve(N);
}
Span::~Span(){};

Span::Span(const Span &cpy)
{
	(void)cpy;
}
Span &Span ::operator=(const Span &cpy)
{
	(void)cpy;
	return(*this);
}
void Span::addNumber(unsigned int num)
{
	if(val.size()>= N)
	{
		throw(std::runtime_error("en peux pas rajouter des numbre"));
	}
	val.push_back(num);
}
//tri a bulle
void Span::bubbleSort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
} 
int Span::shortestSpan(void)
{
	if(val.size() <= 1)
		throw(std::logic_error("il faux minnimum 2 numbre pour calculer distance"));
	std::sort(val.begin(),val.end());
	int min=val[1]-val[0];
	for(size_t i=2;i< val.size();i++)
	{
		int minspam=val[i]-val[i-1];
		if(minspam< min)
		{
			min=minspam;
		}
	}
	return(min);

}

int Span::longestSpan(void)
{
	if(val.size() <= 1)
		throw(std::logic_error("il faux minnimum 2 numbre pour calculer distance"));
	//tri a bulle
	bubbleSort(val);
	int max= val.back() - val.front();
	return(max);

}
void Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end) 
{
	size_t rangeSize = std::distance(begin, end);
	if (val.size() + rangeSize > N) 
    	throw std::runtime_error("en peux pas rajouter des numbre");
	val.insert(val.end(), begin, end);
}