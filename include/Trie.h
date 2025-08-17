#ifndef TRIE_H
#define TRIE_H
#include <vector>
#include <string>
#include "TrieNode.h"

class Trie {
    private:
        TrieNode* root;
        int charToIndex(char c);
        void collectAllWords(TrieNode* curr, std::string prefix, std::vector<std::string> &res); 
        
    public:
        Trie();
        void insert(std::string word);
        bool autocomplete(std::string prefix, std::vector<std::string> &res);
};
#endif