#include <iostream>
#include <vector>

template<typename T>
// requires Incrementable<T>
T sum1(const std::vector<T>& v, T s) {
    for (auto x : v) s += x;
        return s;
}

template<typename T>
// requires Addable<T>
T sum2(const std::vector<T>& v, T s) {
    for (auto x : v) s = s + x;
    return s;
}

int main() {
    
    std::cout << '\n';
    
    std::vector vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    std::cout << "sum1(vec, 0): " << sum1(vec, 0) << '\n';
    std::cout << "sum2(vec, 10): " << sum2(vec, 10) << '\n';

}    