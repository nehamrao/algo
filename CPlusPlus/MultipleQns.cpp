// Determine the second largest elment in a BST
TreeNode* getSecondLargestFromBST (TreeNode* root)
{
    return getSecondLargestBSTHelper (root, NULL);

}

TreeNode* getSecondLargestBSTHelper (TreeNode* current, TreeNode* prev)
{
    if (!current)
        return NULL;
    
    // Base Case
    if (current->right == NULL)
        return prev;
    
    return getSecondLargestBSTHelper (current->right, current);

}

int max (int a, int b)
{
    if (a >= b) return a;
    return b;
}

vector<vector<int>> make_new_Tuple (int index, vector<vector<int>> old)
{
    vector<vector<int>> ret;
    for (int i = index, i++; i < old.size()) {
        ret.push_back(old[i]);
    }
}

// The CAKE thief problem
#include <iostream>
#include <vector>

using namespace std;

class Cake {
  public:
    int weight;
    int value;
    Cake(int w, int v) {
      weight = w;
      value = v;
    }
};

int max (int a, int b)
{
    if (a >= b) return a;
    return b;
}

// The CAKE thief problem
int max_duffel_bag_value(vector<Cake*> cakes, int index, int capacity, int profit)
{
    // Validate input
    if (capacity < 0 || cakes.size() == 0)
        return 0;
    
    // Base case: Finished processing
    if (index >= cakes.size())
        return profit;
    
    // Recursion: Process 'index'
    int cakeProfit = max(max_duffel_bag_value(cakes, 
                                              index + 1,
                                              capacity - cakes[index]->weight,
                                              profit + cakes[index]->value), 
                        max_duffel_bag_value(cakes, 
                                              index + 1,
                                              capacity,
                                              profit));
    return cakeProfit;
}


// To execute C++, please define "int main()"
int main() {
  vector<Cake*> v;
  v.push_back(new Cake(20, 10));
  v.push_back(new Cake(40, 88));
  v.push_back(new Cake(2, 21));
  v.push_back(new Cake(66, 2));
  
  cout << max_duffel_bag_value (v, 0, 24, 0);
  return 0;
}

/*
 * You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed,
 * the only constraint stopping you from robbing each of them is that
 * adjacent houses have security system connected and it will automatically
 * contact the police if two adjacent houses were broken into on the same
 * night. Given a list of non-negative integers representing the amount
 * of money of each house, determine the maximum amount of money you 
 * can rob tonight without alerting the police. 
 * [45, 43, 23, 334, 5, 12]
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        
        return robhelper(nums, 0);  
    }
    
    int max (int a, int b)
    {
        if (a >= b) return a;
        return b;
    }

    int robhelper (vector<int>& nums, int index) {
        
        if (nums.size() == 0 || (index > nums.size() - 1))
            return 0;
            
        int steal  = max(nums[index] + robhelper(nums, index + 2), robhelper(nums, index + 1));
        
        return steal;
    
    }
};


class Solution {
public:
    int rob(TreeNode* root) {
        
        // Base case
        if (!root)
            return 0;
            
        // Recursion
        
        //CASE A: Rob current node
        int currRob = root->val;
        // If left child exists
        if (root->left) {
            currRob += rob(root->left->left) + rob(root->left->right);
        }
        // If right child exists
        if (root->right) {
            currRob += rob(root->right->left) + rob(root->right->right);
        }
        
        //CASE B: Rob next level node
        int nextRob = rob(root->left) + rob(root->right);
        
        int money = max(currRob, nextRob);
        
        return money;
    }
};




