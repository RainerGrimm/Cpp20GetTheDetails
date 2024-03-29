#include <format>
#include <iostream>
#include <iterator>
#include <string>
 
int main() {
    
    std::cout << '\n';

    std::cout << std::format("Hello, C++{}!\n", "20") << '\n';

    std::string buffer;
 
    std::format_to( std::back_inserter(buffer), "Hello, C++{}!\n", "20");    
        
    std::cout << buffer << '\n';
    
    std::cout << '\n';
   
}