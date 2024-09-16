#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
class Rbn
{
    public:
        Rbn();
        Rbn(const Rbn &cpy);
        Rbn &operator=(const Rbn &cpy);
        int ClaculRbn(const std::string &argv);
};
#endif 