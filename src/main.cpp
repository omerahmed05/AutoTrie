#include "Trie.h"
#include "TrieNode.h"
#include <iostream>
#include <string>

int main () {
    while (true) {
        std::cout << "Enter a prefix: ";
        std::string prefix{};
        std::cin >> prefix;

        std::cout << "Autocomplete suggestions: \n";
        // retrieve vector of words with that prefix
        // loop through each word and print it out
        
        std::cout << "Would you like to enter another word for autocomplete? (1 = Yes, 0 = No): ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            continue;
        } else if (choice == 0) {
            std::cout << "Goodbye! \n";
            break;
        }
    }

    return 0;
}