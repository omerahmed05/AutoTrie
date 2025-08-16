/**
 * the character that the trienode represents is determined by its index in the childrens array
 */
struct TrieNode {
    TrieNode* children[26] = {nullptr}; // array of pointers where each pointer in the array points to a TrieNode
                                            // every pointer is initialized to point to nullptr, which means no word continues with that letter from here
                                        // size of array is 26 because there are 26 letters in the english alphabet
    bool isEndOfWord = false;                                   
};