#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printPermutations( vector<vector<int>> *result) {
    
    int cnt = 0;
    for (int i = 0; i < result->size(); i++) {
        for (int j = 0; j < result->at(i).size(); j++) {
             cout<<result->at(i).at(j) << " ";
        }
        cout<<"\n";
        cnt++;
    }
    cout << "Generated " << cnt <<  " permutations of input\n";
}

void swapVector (vector<int> *v, int id1, int id2) {
    if (v) {
        
        int temp = v->at(id1);
        v->at(id1) = v->at(id2);
        v->at(id2) = temp;
    }
    return;
}

void permute (vector<vector<int>> *result, vector<int> *inp,  int start) {
    // Validate input
    if (!inp) {
        cout << "Empty input\n";
        return;
    }
    // Base case: Reached beyond length of input
    if (start >= inp->size()) {
        result->push_back(*inp);
        return;
    } else {
        for (int i = start; i < inp->size(); i++) {
            unordered_map<int, int> m;
            // Make a copy of the input, before recursing
            vector<int> cpy = *inp;
            
            // If i hasn't been fixed at start before, do so now, recurse
            if (m.find(inp->at(i)) == m.end()) {
                m.insert({i, i});
                swapVector(&cpy, i, start);
                permute(result, &cpy, start+1);
            }
            
        }
    }
}

void generatePermute (vector<int> v)
{
    if (v.size() == 0) {
        cout<<"Please provide valid input.\n";
        return;
    }

    vector<vector<int>> result;
    permute(&result, &v, 0);
    printPermutations(&result);
}

int main() {
    vector<int> v = {1,2,3,4};
    generatePermute(v);
    return 0;
}
