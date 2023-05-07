#include <iostream>

const char* g() { 
    return "dynamic initialization"; 
}

constexpr const char* f(bool p) { 
    return p ? "constant initializer" : g(); 
}
 
constinit const char* c = f(true);  // OK
// constinit const char* d = f(false); // ERROR

int incrementValue() {
    constinit static int val = 5;
    return ++val;
}

int main() {
    
    std::cout << '\n';
    
    std::cout << "incrementValue(): " << incrementValue() << '\n';
    
    std::cout << '\n';
    
}