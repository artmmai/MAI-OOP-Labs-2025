#include "../include/replace.hpp"

#include <iostream>
#include <string>

// text - строка для модификации
// n - номер целевой буквы
// old_value - целевой символ
// new_value - символ, который следует использовать в качестве замены

std::string ReplaceEveryNth(const std::string& text, int n, char old_value, char new_value){
    
    std::string result = text;
    int counter = 0;
    int total_counter = 0;

    if (text.empty()){
        std::cout << "Sorry bro, your string is empty.\n";
        return text;
    }

    if (old_value == new_value){
        std::cout << "Sorry bro, your string hasn't changed, because old and new values are same.\n";
        return text;
    }

    if (n <= 0) {
        std::cout << "Sorry bro, your string hasn't changed, because your target letter number is less or equal 0.\n";
        return text;

    }

    for (char letter : text){
        if (letter == old_value){
            total_counter++;
        }
    }

    if (total_counter < n) {
        std::cout << "Sorry bro, your string hasn't changed, because target letter number is bigger than old_value counter.\n";
        return text;
    }

    for (int i = 0; i < result.size(); ++i){
        if (result[i] == old_value){
            counter++;
        }
        if (counter == n) {
            result[i] = new_value;
            counter = 0;
        }
    }

    return result;
}
