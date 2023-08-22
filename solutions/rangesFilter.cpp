#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

template <typename Func, typename Seq>
auto filter(Func func, Seq seq) {
    
    typedef typename Seq::value_type value_type;

    std::vector<value_type> result{};
    for (auto i : seq | std::views::filter(func)) result.push_back(i);
    
    return result;
}


int main() {
    
    std::cout << '\n';
    
    // filter(lambda word: word[0].isupper(), ["Only", "for", "testing", "purpose"]) 
    std::vector<std::string> myStrings{"Only", "for", "testing", "purpose"};
    auto res2 = filter([](const std::string& s){ return static_cast<bool>(std::isupper(s[0])); }, myStrings);
     
    std::cout << "\n\n";
     
    for (auto word: res2) std::cout << word << '\n';
    
    std::cout << '\n';
    
    // len(filter(lambda line: line[0] == "#", open("/etc/services").readlines()))
    std::ifstream file("/etc/services", std::ios::in);
    std::vector<std::string> lines;
    std::string line;
    while(std::getline(file, line)){
        lines.push_back(line);
    }
    std::vector<std::string> commentLines = filter([](const std::string& s){  return s[0] == '#'; }, lines);
    
    std::cout << "Comment lines: " << commentLines.size() << "\n\n";
                                          
}
