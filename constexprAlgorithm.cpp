#include <array>
#include <algorithm>
#include <iostream>

constexpr auto sortCopy(auto cont) {
    std::sort(std::begin(cont), std::end(cont));
    return cont;
}

int main() {

    std::cout << '\n';
    
    constexpr auto arr = sortCopy(std::array {5, -10, 2, 3, 10, -4, 1});
    
    for (auto a: arr) std::cout << a << " ";
    
    static_assert(std::is_sorted(std::begin(arr), std::end(arr)));
    
    std::cout << "\n\n";
    
}