#include "RPN.hpp"
Rbn::Rbn(){}
Rbn::Rbn(const Rbn &cpy){*this=cpy;}
Rbn &Rbn::operator=(const Rbn &cpy)
{
	if(this != &cpy)
		*this=cpy;
	return *this;
}


int Rbn::ClaculRbn(const std::string &argv) {
    std::string token;
    std::stack<int> RBN;

    try {
        std::istringstream str(argv);

        if (!(str >> token) || str.rdbuf()->in_avail() == 0) {
            throw std::runtime_error("Il doit y avoir au moins deux valeurs dans l'expression.");
        }
        do
        {
           if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                int val;
                std::istringstream(token) >> val;
                RBN.push(val);
            } 
            else if (token == "+" || token == "-" || token == "*" || token == "/") {
                if (RBN.size() < 2) {
                    throw std::runtime_error("Il faut deux valeurs dans la pile.");
                }
                int val2 = RBN.top();
                RBN.pop();
                int val1 = RBN.top();
                RBN.pop();
                if (token == "+") {
                    RBN.push(val1 + val2);
                } else if (token == "-") {
                    RBN.push(val1 - val2);
                } else if (token == "*") {
                    RBN.push(val1 * val2);
                } else if (token == "/") {
                    if (val2 == 0) {
                        throw std::runtime_error("Erreur de division par zéro.");
                    } else {
                        RBN.push(val1 / val2);
                    }
                }
            } else {
                throw std::runtime_error("Les valeurs doivent être des entiers.");
            }
        }
        while (str >> token);
        if (RBN.size() == 1) {
            return RBN.top();
        } else if (RBN.empty()) {
            throw std::runtime_error("Il n'y a pas assez d'opérandes dans l'expression.");
        } else {
            throw std::runtime_error("Il reste des valeurs non utilisées dans la pile.");
        }
    } catch (const std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return -999999;
    }
}