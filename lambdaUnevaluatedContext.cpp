#include <stdio.h>
#include <iostream>
#include <memory>
#include <set>
#include <string>

int main() {

    auto StatelessLambda = [](int a, int b){ return a + b; };
    decltype(StatelessLambda)  statelessLambda;   // Default constructor
    
    auto statelessLambda2 = statelessLambda;      // Copy assignment
    
    std::cout << "statelessLambda(2000, 20): " << statelessLambda(2000, 20) << '\n';
    std::cout << "statelessLambda2(2000, 20): " << statelessLambda2(2000, 20) << '\n';
    

    // Unevaluated context
    // C++ Weekly Ep 150
    auto file = std::unique_ptr<FILE, decltype([](FILE* f){ fclose(f); })>{ fopen("MyNewFile.txt", "w")};
    
    // Default constructor and unevaluated context
    std::set<std::string> set1{"this", "is", "only", "for", "testing", "purpose"};
    for (const auto& s: set1) std::cout << s << " ";
    
    std::cout << "\n\n";
    
    using MySet = std::set<std::string, decltype([](const auto& lhs, const auto& rhs){ return lhs.size() < rhs.size(); })>;
    MySet set2{"this", "is", "only", "for", "testing", "purpose"};
    for (const auto& s: set2) std::cout << s << " ";
    
}
    