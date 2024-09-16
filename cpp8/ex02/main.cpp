#include "MutantStack.hpp"
int main()
{
    std::cout << std::endl;
    std::cout << "******************" << std::endl;
    std::cout << "*MutantStack test*" << std::endl;
    std::cout << "******************" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();
    std::cout << "stack cit: ";
    while (cit != cite)
    {
        std::cout << *cit << " ";
        ++cit;
    }
    ++it;
    --it;
    std::cout << "|stack it: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::cout << "stack rit: ";
    while(rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << "|stack crit: ";
    while(crit != crite)
    {
        std::cout << *crit << " ";
        ++crit;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::stack<int> s(mstack);
    std::cout << "top: " << s.top() << std::endl;
    std::cout << std::endl;
    std::cout << "*****************" << std::endl;
    std::cout << "****List test****" << std::endl;
    std::cout << "*****************" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "top: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "size: " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    std::list<int>::const_iterator clist = lst.begin();
    std::list<int>::const_iterator cliste = lst.end();
    std::list<int>::reverse_iterator rlit = lst.rbegin();
    std::list<int>::reverse_iterator rlite = lst.rend();
    std::list<int>::const_reverse_iterator crlit = lst.rbegin();
    std::list<int>::const_reverse_iterator crlite = lst.rend();
    std::cout << "list clist: ";
    while (clist != cliste)
    {
        std::cout << *clist << " ";
        ++clist;
    }
    ++lit;
    --lit;
    std::cout << "|list lit: ";
    while (lit != lite)
    {
        std::cout << *lit << " ";
        ++lit;
    }
    std::cout << std::endl;
    std::cout << "list rlit: ";
    while(rlit != rlite)
    {
        std::cout << *rlit << " ";
        ++rlit;
    }
    std::cout << "|list crlit: ";
    while(crlit != crlite)
    {
        std::cout << *crlit << " ";
        ++crlit;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::list<int> lst2(lst);
    std::cout << "top: " << lst2.back() << std::endl;
    std::cout << std::endl;
    
    return 0;
}