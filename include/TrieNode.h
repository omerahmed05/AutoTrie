// default trienode object:
struct TrieNode {
    TrieNode* children[26] = {nullptr}; // array of pointers where each pointer in the array points to a TrieNode
                                        // every pointer is initialized to point to nothing which means no word continues with that letter from here
    bool isEndOfWord = false;                                  
                                        // size of array is 26 because there are 26 letters in the english alphabet
};