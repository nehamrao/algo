#include <iostream>
#include <vector>

using namespace std;

class Trie {
    public:
        char c;
        Trie* next;
};

Trie* addNodeToTrie (bool create_root, Trie* root, char c)
{
    Trie* ret;
    if (create_root) {
        ret = new Trie();
    } else {
        Trie* temp = root;
        bool end = false;
        while (temp) {
             if (temp->next == NULL && !end) {
                 temp->next = new Trie();
                 temp->next->c = c;
		 temp->next->next = NULL;
		 end = true;
             }
             temp = temp->next;
        }
        Trie* ret = root;
    }
    return ret;
}

string longestCommonPrefix(vector<string>& strs) {
    
    Trie* t = addNodeToTrie (true, NULL, ' ');
    string prev_prefix = "";
    string prefix = "";
     
    // Iterate over the vector of strings
    for (int i = 0; i < strs.size(); i++) {
        // For each string update trie
        for (int j = 0; j < strs.at(i).size(); j++) {
            // Create trie for first string
            if (i == 0) {
	        Trie* root = addNodeToTrie (false, t, strs.at(i).at(j));
                t = root;
            } else {
                // Traverse trie and maintain local prefix string, length
                Trie* temp = t->next;
                while (temp) {
                    if (temp->c == strs.at(i).at(j)) {
                        prefix = prefix + temp->c;
                        if (prefix.size() > prev_prefix.size())
			    prefix = prev_prefix;
                    } else {
                        Trie* root = addNodeToTrie (false, t, strs.at(i).at(j));
                        t = root;
                    }
                    temp = temp->next;
                } 
            }
        }
    }
    return prefix;
}

int main ()
{
   // Trie* root = addNodeToTrie (true, NULL, ' ');
    // Trie* new_root = addNodeToTrie (false, root, 's');
    //if (new_root) {
      //  cout << new_root->next->c << "\n" ;
   // }
   vector<string> str;
   str[0] = "aa";
   str[1] = "aba";  
   string prefix = longestCommonPrefix(str);
   cout << "Prefix: " << prefix;
    
    return 0;

}
