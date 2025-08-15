#include <vector>
#include <string>
#include "TrieNode.h"

class Trie {
    private:
        TrieNode* root;

    public:
        std::vector<std::string> autocomplete(std::string prefix); 
};