/**
 * TODO: Implement Trie class
 * 
 * contains:
 * - insert method that adds a word to the trie
 * - autocomplete method that returns a vector of words with the given prefix in the trie
 *      - once we reach the node corresponding to the last character in the prefix, we perform dfs from the current node
 */
#include "Trie.h"

class Trie {
    private:
        TrieNode* root;

        /**
         * Helper Function:
         * 
         * Use ASCII value to calculate index
         * 
         * a has a ASCII value of 97
         * b has a ASCII value of 98
         * ...
         * ...
         * ...
         * z has a ASCII value of 122
         * 
         * ex: a - a = 0, b - a = 1, c - a = 2, z - a = 25
         */
        int charToIndex(char c) {
            return c - 'a';
        }

    public:
        Trie() {
            root = new TrieNode;
        }

        void insert(std::string word) {
            TrieNode* curr = root;

            for (char c: word) {
                int c_index = charToIndex(c);

                if (curr->children[c_index] == nullptr) {
                    curr->children[c_index] = new TrieNode;
                }

                curr = curr->children[c_index];
            }

            curr->isEndOfWord = true;
        }

        bool autocomplete(std::string prefix, std::vector<std::string> &res) {
            // start at the root of the trie (curr)

            // for each character in the prefix
                // get its index
                // if curr->children[index] == nullptr then it means no words exist with this sequence of characters and return false

            // collect all words with current prefix

            // return true
        }

        void collectAllWords(TrieNode* curr, std::string prefix, std::vector<std::string> &res) {
            
        }
};