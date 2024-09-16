#include <iostream>
#include "Array.hpp"
#include <cstdlib>
/*
int main() {
    // Exemple d'utilisation de la classe Array
    Array<int> tab(5); // Crée un tableau d'entiers de taille 5

    // Remplit le tableau avec des valeurs
    for (unsigned int i = 0; i < tab.getSize(); i++) {
        tab[i] = i * 10;
    }

    // Affiche les éléments du tableau
    for (unsigned int i = 0; i < tab.getSize(); i++) {
        std::cout << "tab[" << i << "] = " << tab[i] << std::endl;
    }

    // Crée une copie du tableau
    Array<int> copyArray = tab;

    // Modifie la copie sans affecter l'original
    copyArray[0] = 100;

    std::cout << "tab[0] = " << tab[0] << std::endl; // L'original n'est pas modifié
    std::cout << "copyArray[0] = " << copyArray[0] << std::endl; // La copie est modifiée

    return 0;
}
*/
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

