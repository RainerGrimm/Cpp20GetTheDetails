module math;

#include <numeric>

int math::add(int fir, int sec) {
    return fir + sec;
}

int math::getProduct(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
}
