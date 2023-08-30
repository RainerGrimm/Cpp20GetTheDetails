#include <chrono>
#include <iostream>

int main() {

     using namespace std::chrono_literals; 
    
     auto timeOfDay = std::chrono::hh_mm_ss(10.5h + 98min + 2020s + 0.5s);                    
    
     std::cout<< std::format("\ntimeOfDay: {:}\n\n", timeOfDay);  

     std::string formatTimeOfDay = "{:25}{:>8}\n";                      

     std::cout << std::vformat(formatTimeOfDay, std::make_format_args("timeOfDay.hours():", timeOfDay.hours()));  
     std::cout << std::vformat(formatTimeOfDay, std::make_format_args("timeOfDay.minutes():", timeOfDay.minutes()));  
     std::cout << std::vformat(formatTimeOfDay, std::make_format_args("timeOfDay.seconds():", timeOfDay.seconds()));  
     std::cout << std::vformat(formatTimeOfDay, std::make_format_args("timeOfDay.subseconds():", timeOfDay.subseconds()));  
     std::cout << std::vformat(formatTimeOfDay, std::make_format_args("timeOfDay.to_duration():", timeOfDay.to_duration()));  

     std::cout << '\n';

     std::cout << std::format("std::chrono::hh_mm_ss(45700.5s): {}\n", std::chrono::hh_mm_ss(45700.5s)); 

     std::cout << '\n';

     std::string formatAm = "{:25}{:6}\n";
     std::cout << std::vformat(formatAm, std::make_format_args("std::chrono::is_am(5h): ", std::chrono::is_am(5h)));                     
     std::cout << std::vformat(formatAm, std::make_format_args("std::chrono::is_am(15h): ", std::chrono::is_am(15h)));            

     std::cout << '\n';
      
     std::string formatMake= "{:26}{:4}\n";
     std::cout << std::vformat(formatMake, std::make_format_args("std::chrono::make12(5h): ", std::chrono::make12(5h)));              
     std::cout << std::vformat(formatMake, std::make_format_args("std::chrono::make12(15h): ", std::chrono::make12(15h))); 

     std::cout << '\n';             

}