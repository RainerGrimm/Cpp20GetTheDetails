#include <concepts>
#include <iostream>

struct Fir {
    int count() const {
        return 2020;
    }
};

struct Sec {
    int size() const {
        return 2021;
    }
};

int main() {

    std::cout << '\n';
   
    Fir fir;
    static_assert(requires(Fir fir){ { fir.count() } -> std::convertible_to<int>; }); 

    Sec sec;
    static_assert(requires(Sec sec){ { sec.count() } -> std::convertible_to<int>; }); 

    int third;
    static_assert(requires(int third){ { third.count() } -> std::convertible_to<int>; }); 

    std::cout << '\n';

}