#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
class PmergeMe
{
	public:
        PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &cpy);
        bool check_int(const char* str);
        void sortFordJohnson(std::vector<int> &vctr) ;
        void	sortFordJohnson(std::deque<int> &deque) ;
        int		binarySearch(std::vector<int> &vctr, int value);
        int		binarySearch(std::deque<int> &deque, int value);
        ~PmergeMe();

        typedef struct s_pair {
			int a;
			int b;
		}t_pair;
	private:
		std::vector<t_pair>	pairs;
		bool	odd;
		int	pending;

};
void parseArguments(int argc, char* argv[],std::vector<int>&av,std::deque<int>&dq );
bool	comparePairs(const PmergeMe::t_pair &pair1, const PmergeMe::t_pair &pair2);
template <typename T>
void print(const T& val, const std::string& msg);
#endif
