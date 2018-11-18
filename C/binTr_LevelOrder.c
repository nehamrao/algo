/* Given a binary tree, return the level order traversal 
 * of its nodes' values. (ie, from left to right, level 
 * by level). 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         // Return list of list of ints
         vector<vector<int>> ret;
         
         // Null check
         if (!root) return ret;
        
        // Define a queue of TreeNodes, push the root
        queue<TreeNode*> q;
        q.push(root);

        // Variable to keep track of number of nodes left in queue
        int currNodesinQ = 1;
       
        // Pointer to a list - used to populate each list of the return list
        vector<int>* resultList = new vector<int>();
        
        while (!q.empty()) {
            
             // Fetch the front of queue & pop it. Update count of nodes in queue
             TreeNode* curr = q.front();
             q.pop();
             currNodesinQ --;
             
             // Push children onto queue
             if (curr->left) q.push(curr->left);
             if (curr->right) q.push(curr->right);
             
             // Push value of retrieved (popped) node from queue to form 1 list of the result
             resultList->push_back(curr->val);
             
             // Attempt to populate next list of final result list once queue is empty
             if (currNodesinQ == 0) {
                 // Only update the number of nodes left in queue to 
                 // ditinguish one depth of nodes from the next
                currNodesinQ = q.size();
                ret.push_back(*resultList);
                resultList = new vector<int>();
             }
             
        }
        
    }
};
