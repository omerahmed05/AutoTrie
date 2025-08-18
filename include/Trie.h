#ifndef TRIE_H
#define TRIE_H
#include <vector>
#include <string>
#include <string_view>
#include "TrieNode.h"

class Trie {
    private:
        TrieNode* root;
        int charToIndex(char c);
        void collectAllWords(TrieNode* curr, std::string& prefix, std::vector<std::string> &res); 
        void deleteSubtree(TrieNode* node);
        
    public:
        Trie(); // constructor
        ~Trie(); // destructor
        void insert(std::string_view word);
        bool autocomplete(std::string_view prefix, std::vector<std::string> &res);
};
#endif