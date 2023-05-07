#include <chrono>
#include <iostream>

int main() {

    std::cout << '\n'

    using namespace std::literals::chrono_literals;
    std::cout << std::format("Default format: {} {}\n", 42s, 100ms) << "\n";

    std::chrono::time_point<std::chrono::system_clock> t = std::chrono::system_clock::now();
    std::cout << std::format("{:%Y-%m-%d %H:%M:%S}", t);

    std::cout << '\n';

}