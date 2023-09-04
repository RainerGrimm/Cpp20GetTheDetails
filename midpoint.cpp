#include <limits>
#include <numeric>
#include <iostream>
 
int main() {

    std::cout << '\n';

    int first = std::numeric_limits<int>::max(); 
    int second = std::numeric_limits<int>::max() - 2;
 
    std::cout << "first: " << first << '\n';
    std::cout << "second: " << second << '\n';

    std::cout << '\n';

    std::cout << "(first + second) / 2: " << (first + second) / 2 << '\n';
    std::cout << "std::midpoint(first, second): " << std::midpoint(first, second) << '\n';

    std::cout << '\n';

}