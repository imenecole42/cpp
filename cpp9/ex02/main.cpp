#include "PmergeMe.hpp"

template <typename T>
void print(const T& val, const std::string& msg) {
    //typename T::const_iterator it;
    std::cout << msg;
    for (size_t i=0; i< val.size(); i++) {
        std::cout << val[i] << " ";
    }
    std::cout << std::endl;
}
void parseArguments(int argc, char* argv[],std::vector<int>&av,std::deque<int>&dq ) {
    for (int i = 1; i < argc; i++) {
        int num = std::atoi(argv[i]);
        if (num >= 0) {
            av.push_back(num);
			dq.push_back(num);
        } 
		else {
            std::cerr << "Error: Invalid value found: " << argv[i] << std::endl;
            exit(1);
        }
    }
}
int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "Error: No integer sequence provided as an argument." << std::endl;
        return 1;
    }
    PmergeMe P;
    PmergeMe D;
    for (int j = 1; j < argc; j++) {
        if (!P.check_int(argv[j])) {
            std::cerr << "Error: Invalid value found: " << argv[j] << std::endl;
            return 1;
        }
    }
    std::vector<int> vctr;
    std::deque<int> deque;
    parseArguments(argc, argv,vctr,deque);
    /*for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) {
			if (!isdigit(argv[i][j])) {
				std::cerr << "Error: bad input.\n";
			}
		}
		int num = atoi(argv[i]);
		if (num < 0) {
			std::cerr << "Error: bad input.\n";
		}
		deque.push_back(num);
		vctr.push_back(num);
	}
    */
    print(vctr, "Before:vector ");
    // Mesure du temps pour std::vector
    clock_t startVector = clock();
    P.sortFordJohnson(vctr);    
    clock_t endVector = clock();
    print(vctr, "After (std::vector): ");
    double durationVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << vctr.size() << " elements with std::vector: " << durationVector << " us" << std::endl;
    // Mesure du temps pour std::deque
    clock_t startList = clock();
    print(deque, "Before:deque ");
    D.sortFordJohnson(deque);
    clock_t endList = clock();
    print(deque, "After (std::deque): ");
    double durationList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << deque.size() << " elements with std::list: " << durationList << " us" << std::endl;
}
  
