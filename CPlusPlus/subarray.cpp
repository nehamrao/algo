#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void printTargetSubary(vector<int> v, int target)
{
    unordered_map<int, int> m;
    unordered_map<int, int>::const_iterator it;
    int pre_sum = 0;
    m.insert(std::make_pair<int, int>(pre_sum, -1));
    for (int i = 0; i < v.size(); i++) {
        pre_sum += v.at(i);
        it = m.find(pre_sum - target);
        m.insert(std::make_pair<int, int>(pre_sum, i));
        if (it != m.end()) {
            for (int j = it->second + 1; j <= i; j++) {
                cout << v.at(j) << " ";
            } cout << "\n";
        }
    }
}

int main (void)
{
   int target = -1;
   int input[] = {-200, 199, 34, 5, 22, 0, -1, 1, -2};
   vector<int> v (input, input + sizeof(input)/sizeof(int));
   printTargetSubary(v, target); 
}
