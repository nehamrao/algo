#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

// neha, nehb, nehbd
// neh --> neha, nehb

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
    
    bool findWordExists (string word) {
        TrieNode* curr = root;
        
        // For each character of the word
        for (auto it = word.begin(); it != word.end(); it++) {
    
            unordered_map<char, TrieNode*>::iterator iter = (curr->m).find(*it);

            // If found char
            if (iter != (curr->m).end()) {
                curr = (curr->m)[*it];
            } else {
                cout << "Word " << word << " not found in trie\n";
                return false;
            }
        }
        
        if (curr->endOfWord) {
            cout << "Found word " << word << " in trie\n"; 
            return true;
        } else {
             cout << "Word "<< word << " not found in trie\n";
             return false;
        }
    }
    
    bool findPrefix (string word) {
        TrieNode* curr = root;
        
        for (auto it = word.begin(); it != word.end(); it++) {
            if ((curr->m).find(*it) == (curr->m).end()) {
                cout << "Prefix " << word << " not in trie\n";
                return false;
            } else {
                curr = (curr->m)[*it];
            }
        }
        cout << "Prefix " << word << " found in trie\n";
        return true;
    }
    
    void autocompleteHelper (TrieNode* t, string* word, vector<string>* result, string* prefix) {
      /*
       * Recursive function to determine all words in trie
       * with the given prefix. Base case: Reached end of word
       */
      if (!t || (findWordExists(*word))) {
            cout << "Here to push result " << *word << "\n";
            result->push_back(*word);
            return;
      }
      
      unordered_map<char, TrieNode*>::iterator it;
      // Recursive case: Iterate over the map of the trie node and recurse
      for (auto it = (t->m).begin(); it != (t->m).end(); it++) {
           cout << "Map found char " << it->first <<"\n";
           *word = *word + it->first; 
           autocompleteHelper(it->second, word, result, prefix);
           word->erase(word->end() - 1);
           cout << "Reset to " << *word << "\n";
      }
    }
  
    void autocomplete (string prefix) {
      // Traverse trie to find prefix
      TrieNode* curr = root;
      
      for (auto it = prefix.begin(); it != prefix.end(); it++) {
           if ((curr->m).find(*it) == (curr->m).end()) {
               cout <<  "Prefix " << prefix << " not in trie\n";
               return;
           } else {
               // Value of that char in the map of trie
               curr = (curr->m)[*it]; 
           }
      }
      
      // At this point, curr will point to the next trie node after the prefix
      string word = prefix;// Push back current prefix
      
      vector<string> result;
      autocompleteHelper(curr, &word, &result, &prefix);
      
      cout << "Autocomplete words are:\n";
      for (int i = 0; i < result.size(); i++) {
          cout << result[i] << "\n";
      }
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
    
    //Test methods
    t->insertWord("neha");
    t->insertWord("nehb");
    t->insertWord("nehbd");
    t->insertWord("nehbdef");
    t->findWordExists("neha");
    bool found = t->findPrefix("neha");
    t->autocomplete("neh");
    return 0;
}