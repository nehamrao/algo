#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


class TrieNode {
  public:
 
    unordered_map<char, TrieNode*> m;
    bool endOfWord;
};


class Trie {
  public:
    TrieNode *root = NULL;
    
    Trie () {
        root = makeTrieNode();
    }
    
    TrieNode *makeTrieNode () {
        TrieNode *t = new TrieNode;
        t->endOfWord = false;
        return t;
    }
    
    void insertWord (string word) {
        TrieNode *curr = root;
        
        for (auto it = word.begin(); it != word.end(); it++) {

            /* If char is not present in map of trie,
             * add it and create new trienode with 
             * endOfWord as false
             */
            unordered_map<char, TrieNode*>::iterator iter = (curr->m).find(*it);
            if (iter == (curr->m).end()) {
                
                TrieNode* next = makeTrieNode();
                (curr->m).insert (make_pair(*it, next));
                
                curr = next;
            } else {
                curr = iter->second;
            }
                    
        }
        curr->endOfWord = true;
    }
    
    void findWordExists (string word) {
        TrieNode* curr = root;
        
        // For each character of the word
        for (auto it = word.begin(); it != word.end(); it++) {
    
            unordered_map<char, TrieNode*>::iterator iter = (curr->m).find(*it);

            // If found char
            if (iter != (curr->m).end()) {
                curr = (curr->m)[*it];
            
            } else {
                cout << "Word " << word << " not found in trie\n";
                return;
            }
            
        }
        

        if (curr->endOfWord && word.length() > 0)
            cout << "Found word " << word << " in trie\n";
        else
            cout << "Word "<< word << " not found in trie\n";
    }
    
    void findPrefix (string word) {
        TrieNode* curr = root;
        
        for (auto it = word.begin(); it != word.end(); it++) {
            if ((curr->m).find(*it) == (curr->m).end()) {
                cout << "Prefix " << word << " not in trie\n";
            } else {
                curr = (curr->m)[*it];
            }
        }
        cout << "Prefix " << word << " found in trie\n";
    }
    
    void deleteWord (string word) {
        // Word not present
        // Find end of word, that node has empty map => delete node
        // now remove entry from prev map
        // now if no other entries in map, repeat
        // else done
        // If end of word node has non-empty map, set eow false

    }
};

int main() {
    Trie *t = new Trie();
    
    // Test methods
    t->insertWord("neha");
    t->insertWord("nena");
    t->insertWord("gudla");
    t->insertWord("dddd");
    t->findWordExists("p98o");
    t->findPrefix("neh");
    return 0;
}
