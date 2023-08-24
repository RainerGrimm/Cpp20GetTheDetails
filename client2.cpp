#include <iostream>
#include "client2Header.h"

int main() {
    
    std::cout << '\n';     
   
    auto [val, message] = math::sum(2000, 11);
    std::cout << "math::sum(2000, 11): " << val << "; type: " << message << '\n';
    
    auto [val1, message1] =  math::sum(2013.5, 0.5);
    std::cout << "math::sum(2013.5, 0.5): " << val1 << "; type: " << message1 << '\n';
    
    auto [val2, message2] =  math::sum(2017, false);
    std::cout << "math::sum(2017, false): " << val2 << "; type: " << message2 << '\n';
    
}