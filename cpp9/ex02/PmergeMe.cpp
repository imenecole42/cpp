#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& cpy) : pairs(cpy.pairs){}

PmergeMe::~PmergeMe() {}

PmergeMe	&PmergeMe::operator=(const PmergeMe& cpy) {
	if (this != &cpy) {
        pairs = cpy.pairs;
        odd = cpy.odd;
        pending = cpy.pending;
    }
    return *this;
}
bool  PmergeMe::check_int(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]) && str[i] == ' ') {
            return false;
        }
    }
    return true;
}
/*Vecteur trié : [ 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 ]
Valeur recherchée : 12

Itération 1 : left = 0, right = 9, mid = 4 (valeur 10)
              On ajuste left = mid + 1 (left = 5)

Itération 2 : left = 5, right = 9, mid = 7 (valeur 16)
              On ajuste right = mid - 1 (right = 6)

Itération 3 : left = 5, right = 6, mid = 5 (valeur 12)
              Valeur trouvée à l'indice 5, on retourne cet indice.
*/
int PmergeMe::binarySearch(std::vector<int> &vctr, int value) {
    int left = 0; 
    int right = vctr.size() - 1; 
    while (left <= right) { 
        int mid = left + (right - left) / 2; 

        if (vctr[mid] == value) 
            return mid; 

        if (vctr[mid] < value) 
            left = mid + 1; 

        else 
            right = mid - 1; 
    }

    return left; 
}
/*    Étape 1: Vérification de la parité (odd = true/false)
                |
                v
     [ 5, 7, 3, 8, 2 ]   <-- Vecteur d'entrée (vctr)
                |
                v
    Étape 2: Création des paires (pairs)
                |
                v
    [ {7, 5}, {8, 3} ]   <-- Paires (pairs)
                |
                v
    Étape 3: Gestion de l'élément non apparié (pending)
                |
                v
              2         <-- Élément en attente (pending)

1. Vecteur 'vctr' après vctr.clear() : [] 

2. Ajout des éléments 'a' des paires :
   - vctr = [4, 6, 8]

3. Insertion des éléments 'b' des paires :
   - vctr = [2, 3, 4, 5, 6, 8]

4. Insertion de l'élément en attente ('pending') :
   - vctr = [2, 3, 4, 5, 6, 7, 8]
*/
void	PmergeMe::sortFordJohnson(std::vector<int> &vctr) {
	odd = (vctr.size() % 2 == 1);

    for (size_t i = 0; i < vctr.size() - odd; i += 2) {
        int first = vctr[i];
        int second = vctr[i + 1];

        int max = (first > second) ? first : second;
        int min = (first > second) ? second : first;

        t_pair pair;
        pair.a = max;
        pair.b = min;

        pairs.push_back(pair);
    }
	if (odd) 
        pending = vctr[vctr.size() - 1];
	std::sort(pairs.begin(), pairs.end(), comparePairs);
	vctr.clear(); 

    for (size_t i = 0; i < pairs.size(); i++)
        vctr.push_back(pairs[i].a);

    for (size_t i = 0; i < pairs.size(); i++)
        vctr.insert(vctr.begin() + binarySearch(vctr, pairs[i].b), pairs[i].b);

    if (odd && pending != -1)
        vctr.insert(vctr.begin() + binarySearch(vctr, pending), pending);
}

int PmergeMe::binarySearch(std::deque<int> &deque, int value) {
    int left = 0; 
    int right = deque.size() - 1; 

    while (left <= right) { 
        int mid = left + (right - left) / 2; 

        if (deque[mid] == value) 
            return mid; 

        if (deque[mid] < value) 
            left = mid + 1; 

        else 
            right = mid - 1;
    } 

    return left; 
}
void	PmergeMe::sortFordJohnson(std::deque<int> &deque) {
	odd = (deque.size() % 2 == 1);

    for (size_t i = 0; i < deque.size() - odd; i += 2) {
        int first = deque[i];
        int second = deque[i + 1];

        int max = (first > second) ? first : second;
        int min = (first > second) ? second : first;

        t_pair pair;
        pair.a = max;
        pair.b = min;

        pairs.push_back(pair);
    }
	if (odd) 
        pending = deque[deque.size() - 1];
	std::sort(pairs.begin(), pairs.end(), comparePairs);
	deque.clear(); 

    for (size_t i = 0; i < pairs.size(); i++)
        deque.push_back(pairs[i].a);

    for (size_t i = 0; i < pairs.size(); i++)
        deque.insert(deque.begin() + binarySearch(deque, pairs[i].b), pairs[i].b);

    if (odd && pending != -1)
        deque.insert(deque.begin() + binarySearch(deque, pending), pending);
}

bool	comparePairs(const PmergeMe::t_pair &pair1, const PmergeMe::t_pair &pair2) {
	return (pair1.a < pair2.a);
}
