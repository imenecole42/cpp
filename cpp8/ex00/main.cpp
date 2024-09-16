#include "easyfind.hpp"
int main()
{
    std::vector<int> V ;
	V.push_back(1);
    V.push_back(2);
    V.push_back(3);
    V.push_back(4);
    V.push_back(5);
 	try {
        int val = 3;
        std::vector<int>::iterator result = Easyfind(V, val);
        std::cout << "Found " << val << " at index " << (result - V.begin()) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}