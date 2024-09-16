#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>
#include <stdint.h>
#include <string>
struct Data {
    int value;
    Data(int v) : value(v) {}
	Data() : value(0){}
};

#endif 