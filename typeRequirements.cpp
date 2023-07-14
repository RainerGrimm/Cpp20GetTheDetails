#include <iostream>
#include <vector>

template <typename T>
struct Other{};

template<typename T> 
concept TypeRequirement = requires {
    typename T::value_type; 
    typename Other<T>;     
};

int main() {

    std::cout << '\n';

    TypeRequirement auto myVec= std::vector<int>{1, 2, 3};

    std::cout << '\n';

}