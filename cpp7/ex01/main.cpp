#include <iostream>
// Function template 'iter' that takes an array, its length, and a function to apply to each element.
#include "inter.hpp"

// int main() {
//     int T[] = {1, 2, 3, 4, 5};
//     double D[] = {1.1, 2.2, 3.3, 4.4, 5.5};
//     char charArray[] = "Hello";

//     std::cout << "Int Array: "<<std::endl;
//     iter(T, 5, printElement<int>);
    
//     std::cout << "\nDouble Array: "<<std::endl;
//     iter(D, 5, printElement<double>);
    
//     std::cout << "\nChar Array: "<<std::endl;
//     iter(charArray, 5, printElement<char>);
    
//     std::cout << std::endl;

//     return 0;
// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print< Awesome> );

  return 0;
}
