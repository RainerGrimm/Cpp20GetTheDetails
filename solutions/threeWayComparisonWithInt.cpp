#include <compare>
#include <iostream>

struct MyInt {
    int value;
    constexpr explicit MyInt(int val): value{val} { }
    auto operator<=>(const MyInt& rhs) const = default;  
    constexpr auto operator<=>(const int& rhs) const {
        return value <=> rhs;
    }
};

template <typename T, typename T2>
constexpr bool isLessThan(const T& lhs, const T2& rhs) {
    return lhs < rhs;
}

int main() {
    
    std::cout << std::boolalpha << '\n';
    
    constexpr MyInt myInt2011(2011);
    constexpr MyInt myInt2014(2014);
    
    constexpr int int2011(2011);
    constexpr int int2014(2014);
    
    std::cout << "isLessThan(myInt2011, myInt2014): "
              << isLessThan(myInt2011, myInt2014) << '\n';
              
    std::cout << "isLessThan(int2011, myInt2014): "
              << isLessThan(int2011, myInt2014) << '\n';
            
    std::cout << "isLessThan(myInt2011, int2014): "
              << isLessThan(myInt2011, int2014) << '\n';
              
    constexpr auto res = isLessThan(myInt2011, int2014);
              
    std::cout << '\n';
              
}
