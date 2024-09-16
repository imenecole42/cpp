#ifndef INTER_HPP
#define INTER_HPP
#include <iostream>
template <typename T, typename Func>
void iter( T* array, size_t length, Func f) {
    for (size_t i = 0; i < length; ++i) {
        f(array[i]);
    }
}

// Example function that can be used as the third parameter for testing
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}
#endif
