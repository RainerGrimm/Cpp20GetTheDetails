#include <format>
#include <iostream>

struct Point1 {
    int x;
};

struct Point2 {
    int x;
    int y;
};

template <>
struct std::formatter<Point1> {
    std::formatter<int> intFormater;

    constexpr auto parse(std::format_parse_context& ctx) {
        return intFormater.parse(ctx);
    }

    auto format(const Point1& po, std::format_context& ctx) const {
        return intFormater.format(po.x, ctx);
    }
};

template <>
struct std::formatter<Point2> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    auto format(const Point2& po, std::format_context& ctx) const {
        return std::format_to(ctx.out(), "({}, {})", po.x, po.y);
    }
};


int main() {

    std::cout << '\n';

    std::cout << "Point1(3): " << std::format("{}",Point1(3)) << '\n';
    std::cout << "Point2(3, 7): " << std::format("{}", Point2(3, 7));

    std::cout << '\n';

}