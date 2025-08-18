#include "Trie.h"

Trie::Trie() {
    root = new TrieNode();
}

/**
 * Automatically called when Trie object goes out of scope
 */
Trie::~Trie() {
    deleteSubtree(root);
}

void Trie::deleteSubtree(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < 26; i++) {
        deleteSubtree(node->children[i]);
    }
    delete node;
}

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
int Trie::charToIndex(char c)
{
    if (c >= 'A' && c <= 'Z') {
        c = c + 32; // Convert uppercase to lowercase
    }
    
    // Only process lowercase letters a-z
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    
    // For non-alphabetic characters
    return -1;
}

void Trie::collectAllWords(TrieNode *curr, std::string &curr_word, std::vector<std::string> &res)
{
    // dfs

    // If the current path forms a full word, add it to res
    if (curr->isEndOfWord)
    {
        res.push_back(curr_word);
    }

    // For each TrieNode in the TrieNode array for the current TrieNode:
    // if its null, skip and check if we can continue from other characters
    // add the current character to the curr_word
    // call collect all words

    for (int i = 0; i < 26; i++)
    {
        if (curr->children[i] != nullptr)
        {
            char next_letter = 'a' + i; // (ASCII Value of 'a') + Index of Character = 97 + i
                                        // ex: 97 + 0 = 97 = a, 97 + 1 = 98 = b, ...
            curr_word.push_back(next_letter);
            collectAllWords(curr->children[i], curr_word, res);
            curr_word.pop_back();
        }
    }
}

void Trie::insert(std::string_view word)
{
    TrieNode *curr = root;

    for (char c : word)
    {
        int c_index = charToIndex(c);
        
        if (c_index == -1) {
            continue;
        }

        if (curr->children[c_index] == nullptr)
        {
            curr->children[c_index] = new TrieNode;
        }

        curr = curr->children[c_index];
    }

    curr->isEndOfWord = true;
}

bool Trie::autocomplete(std::string_view prefix, std::vector<std::string> &res)
{
    // start at the root of the trie (curr)
    TrieNode *curr = root;

    // for each character in the prefix, traverse the trie
    // get its index
    // if curr->children[index] == nullptr then it means no words exist with this sequence of characters and return false
    // else update curr

    for (char c : prefix)
    {
        int char_index = charToIndex(c);
        
        if (char_index == -1) {
            return false;
        }

        if (curr->children[char_index] == nullptr)
        {
            return false;
        }
        else
        {
            curr = curr->children[char_index];
        }
    }

    // collect all words with current prefix
    std::string prefix_str(prefix); 
    collectAllWords(curr, prefix_str, res); // pass a real std::string object, not a temporary

    // return true
    return true;
};
