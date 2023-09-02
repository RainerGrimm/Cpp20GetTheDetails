#include <bit>
#include <bitset>
#include <format>
#include <iostream>
#include <string>
 
int main() {

    std::cout << '\n';
    
    std::cout << std::boolalpha;

    std::string formatString = "{:#010b}";
    
    for (auto i = 0u; i < 16u; ++i) {

        auto form =  std::vformat(formatString, std::make_format_args(i));

        std::cout << "has_single_bit(" << form << ") = " << std::has_single_bit(i) << '\n';
        std::cout << "bit_ceil(" << form << ") = " << std::bit_ceil(i) << '\n';
        std::cout << "bit_width(" << form << ") = " << std::bit_width(i) << '\n';
        std::cout << "popcount(" << form << ") = " << std::popcount(i) << '\n';   
        
        std::cout << '\n';
    }
    
    std::cout << '\n';
    
}