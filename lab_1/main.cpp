#include <iostream>
#include "include/replace.hpp"

int main(){
    std::string text;
    int n;
    char old_value, new_value;
    std::cout << "Enter your string:\n";
    std::getline(std::cin, text);
    std::cout << "Enter target letter number:\n";
    std::cin >> n;
    std::cout << "Enter target letter:\n";
    std::cin >> old_value;
    std::cout << "Enter replaceble letter:\n";
    std::cin >> new_value;
    //std::string result = ReplaceEveryNth(text, 2, 'a', 'o');
    std::cout << "Catch your string brother:\n";
    std::cout << ReplaceEveryNth(text, n, old_value, new_value) << "\n";
    return 0;
}
