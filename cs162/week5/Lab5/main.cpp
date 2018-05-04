#include <iostream>
#include "function1.hpp"

int main() {
    // Reverse string function testing
    // Given: "Hello, World" -> reverseString() -> "dlroW ,olleH"
    std::string word = "";
    bool valid = false;
    do {
        try {
            int i = 0;
            std::getline(std::cin, word);
            if (word.length() > i) {     // Empty World
                valid = true;
            }
        } catch (const std::out_of_range &error) {
            std::cerr << "[Error]: out of range " << error.what() << "\n";
        }
    } while (!valid);
    reverseString(word);
    return 0;
}