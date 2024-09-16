#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include <cstdlib>
#include <cctype>
class Btc
{
    public:
    Btc();
    Btc(const Btc &cpy);
    Btc &operator=(const Btc &cpy);
    ~Btc();
    bool isvaliddate(const std::string&date);
    typedef std::map<std::string, float> dataBase;
    dataBase parse_date(const std::string& fd);
    float lookupValue(const dataBase& data, const std::string& date);
};
#endif