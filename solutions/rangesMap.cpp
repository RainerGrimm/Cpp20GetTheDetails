#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>
#include <utility>


template <typename Func, typename Seq>
auto map(Func func, Seq seq) {
    
    typedef typename Seq::value_type value_type;
    using return_type = decltype(func(std::declval<value_type>()));  

    std::vector<return_type> result{};
    for (auto i :seq | std::views::transform(func)) result.push_back(i);
    
    return result;
}

int main() {
    
    std::cout << '\n';
    
    // map(lambda word: (len(word), word), ["Only", "for", "testing", "purpose."])
    std::vector<std::string> myStrings{"Only", "for", "testing", "purpose"};
    auto res2 = map([](const std::string& s){ return std::make_pair(s.size(), s); }, myStrings);
    
    for (auto p: res2) std::cout << "(" <<  p.first << ", " << p.second << ") " ;
    
    std::cout << "\n\n";
    
    // freqWord = map(lambda word: (len(word), word), open("/etc/services").read().split("\n"))
    // freqWord.sort(reverse = True)
    // freqWord[:3]    
    std::ifstream file("/etc/services", std::ios::in);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string text = buffer.str();

    std::vector<std::string> words = text | std::views::split('\n');
    auto lengthWords = map([](const std::string& s){ return std::make_pair(s.size(), s); }, words);
    std::sort(std::begin(lengthWords), std::end(lengthWords), std::greater);
    std::for_each(std::begin(lengthWords), std::begin(lengthWords) + 3, [](const auto& p) {
        std::cout << p.first << " " << p.second << '\n';
    });
       
    std::cout << '\n';
    
}
