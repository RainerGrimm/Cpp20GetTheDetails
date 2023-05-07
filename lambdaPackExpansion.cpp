#include <functional>
#include <iostream>
#include <utility>

template<class Callable, class... Args>
auto bindArguments11(Callable callable, Args... args) {
    return [=] {
        return callable(args...);
    };
}

template<class Callable, class... Args>
auto bindArguments20(Callable callable, Args... args) {
    return [callable = std::move(callable), ...args = std::move(args)] {
        return callable(args...);
    };
}


int plus3(int lhs, int rhs) {
    return lhs + rhs;
}

int main() {
    
    std::cout << '\n';
    
    auto funcPlus1 = bindArguments11(std::plus<int>(), 2000, 20);
    std::cout << "funcPlus1(): " << funcPlus1() << '\n';
    auto funcPlus2= bindArguments11([](int lhs, int rhs) { return lhs + rhs; }, 2000, 23);
    std::cout << "funcPlus2(): " << funcPlus2() << '\n';
    auto funcPlus3= bindArguments11(plus3, 2000, 26);
    std::cout << "funcPlus3(): " << funcPlus3() << '\n';
    
    std::cout << '\n';
    
    auto funcPlus4 = bindArguments20(std::plus<int>(), 2000, 20);
    std::cout << "funcPlus4(): " << funcPlus4() << '\n';
    auto funcPlus5= bindArguments20([](int lhs, int rhs) { return lhs + rhs; }, 2000, 23);
    std::cout << "funcPlus5(): " << funcPlus5() << '\n';
    auto funcPlus6= bindArguments20(plus3, 2000, 26);
    std::cout << "funcPlus6(): " << funcPlus6() << '\n';
    
    
    
    std::cout << '\n';
}