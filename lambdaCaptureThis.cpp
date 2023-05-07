#include <iostream>
#include <string>

struct Lambda {
    auto foo() const {
        return [=] { std::cout << s << '\n'; };      
    }
    std::string s = "lambda";
     ~Lambda() {
        std::cout << "Goodbye" << '\n';
    }
};

auto makeLambda() {                                               
    Lambda lambda;
    return lambda.foo();
}                                                                                      


int main() {
    
    std::cout << '\n';

    auto lam = makeLambda();                                
    lam();                                                                       
    
    std::cout << '\n';
    
}