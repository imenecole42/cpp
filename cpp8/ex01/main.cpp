#include "Span.hpp"
//main sujet
int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
/*
//main pour addnumber
int main() {
    try {
        Span span(10000); // Crée un objet Span pouvant stocker 10 000 nombres.

        // Remplissez Span avec 10 000 nombres.
        for (int i = 1; i <= 10000; ++i) {
            span.addNumber(i);
        }

        // Testez la plus courte et la plus longue distance.
        int shortest = span.shortestSpan();
        int longest = span.longestSpan();

        std::cout << "Shortest span: " << shortest << std::endl;
        std::cout << "Longest span: " << longest << std::endl;

        // Essayez d'ajouter un autre nombre après que Span soit plein (doit générer une exception).
        span.addNumber(10001);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

//main pour rang iterateur
int main() {
    try {
        Span span(10000); // Crée un objet Span pouvant stocker 10 000 nombres.

        // Remplir Span avec une plage d'itérateurs.
        std::vector<int> sp;
        for (int i = 1; i <= 10000; ++i) {
            sp.push_back(i);
        }
        span.addRange(sp.begin(), sp.end());

        int shortest = span.shortestSpan();
        int longest = span.longestSpan();

        std::cout << "Shortest span: " << shortest << std::endl;
        std::cout << "Longest span: " << longest << std::endl;

    } 
	catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
*/
