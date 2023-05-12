#include <format>
#include <iostream>

int main() {

    std::cout << std::format("{:+06d}", 120) << '\n';
    std::cout << std::format("{:#06b}", 1010101) << '\n';
    std::cout << std::format("{:0>15}", 120) << '\n';
    std::cout << std::format("{:#06x}", 0xa)  << '\n';

}
