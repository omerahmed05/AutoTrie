#include "Trie.h"
#include <iostream>
#include <fstream>

int main () {
    // load the dictionary
    std::ifstream dictionary("dictionary.txt");
    // initiaize trie object
    Trie* trie = new Trie();

    std::string word;

    // insert every word into the trie
    while (std::getline(dictionary, word)) {
        trie->insert(word);
    }

    while (true) {
        std::cout << "Enter a prefix: ";
        std::string prefix{};
        std::cin >> prefix;

        std::cout << "Autocomplete suggestions: \n";

        // retrieve vector of words with that prefix
        std::vector<std::string> words;
        trie->autocomplete(prefix, words); // calle function signature decides whether we modify the vector in place or not through the use of &

        // loop through each word and print it out
        if (words.size() == 0) {
            std::cout << "No words found with that prefix. \n";
        } else {
            for (int i = 0; i < words.size(); i++) {
                std::cout << "- " << words[i] << "\n";
            }
        }

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