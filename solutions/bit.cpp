#include <bit>
#include <bitset>
#include <iostream>
 
int main() {

    std::cout << '\n';
    
    std::cout << std::boolalpha;
    
    for (auto i = 0u; i < 16u; ++i) {
        std::cout << "has_single_bit(" << std::bitset<8>(i) << ") = " << std::has_single_bit(i) << '\n';
        std::cout << "bit_ceil(" << std::bitset<8>(i) << ") = " << std::bit_ceil(i) << '\n';
        std::cout << "bit_width(" << std::bitset<8>(i) << ") = " << std::bit_width(i) << '\n';
        std::cout << "bit_popcount(" << std::bitset<8>(i) << ") = " << std::popcount(i) << '\n';   
        
        std::cout << '\n';
    }
    
    std::cout << '\n';
    
}