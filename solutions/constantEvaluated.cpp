#include <iostream>
#include <string>
#include <type_traits>
 
constexpr int yingYang() {
    if (std::is_constant_evaluated() ) return 20;
    else return 10;
}
 
int main() {
    
    std::cout << '\n';
   
    constexpr auto cmpTime = yingYang();
    std::cout << "compile-time: " << cmpTime << '\n';
    std::cout << "run-time: " << yingYang();
 
    std::cout << '\n';
    
}