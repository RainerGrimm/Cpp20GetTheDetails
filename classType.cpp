struct ClassType {
    constexpr ClassType(int) {}
};

template <ClassType cl>
auto getClassType() {
    return cl;
}

int main() {

    auto cl = getClassType<ClassType(2020)>();
    
}