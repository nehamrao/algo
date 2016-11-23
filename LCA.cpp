/* [A] [Question]: Determine the LCA of a BST */
struct TreeNode {
  int val;
    TreeNode* left;
    TreeNode* right;
};

/* Recursively, determine where the two nodes lie in a BST 
--------------------------------------------------------
Time Complexity = O(h) where h is the height of the tree
Space Complexity = O(h) of stack space for the recursion
--------------------------------------------------------
*/
TreeNode* findLCA(TreeNode* root, TreeNode *a, TreeNode* b)
{
    if (!root || !a || !b)
        return null;
    
    if (a->val < root->val && b < root->val) {
        // Case 1: Both of the node values are < than root
        return findLCA(root->left, a, b);
    } else if (a->val > root->val && b->val > root->val) {
        // Case 2: Both of the node values are > than root
        return findLCA(root->right, a, b);
    } else {
        // Case 3: Either of the nodes is equal to current root
        // Case 4: One node is on the left and other is on the right
        return root;
    }
}

/*Iteratively, determine where the two nodes lie in a BST 
--------------------------------------------------------
Time Complexity = O(h) where h is the height of the tree
Space Complexity = O(1) no extra space needed
--------------------------------------------------------
*/
TreeNode* findLCA(TreeNode* root, TreeNode *a, TreeNode *b)
{
    while (root && a && b) {
        
        if (a->val < root->val && b->val < root->val)
            root = root->left;
        else if (a->val > root->val && b->val > root->val)
            root = root->right;
        else
            return root;
    }
    return root;
}

/* [B] [Question]: Determine the LCA of a Binary Tree */

/* Method 1: 
One can find the root to leaf paths with
node a and node b and compare two path vectors to determin
the LCA.
--------------------------------------------------------
Time Complexity = O(n) where n is the number of nodes 
Space Complexity =  O(log(n))
--------------------------------------------------------
*/

bool areChildrenVisited (TreeNode *curr, TreeNode *prev)
{
    if (curr->left && !curr->right)
        if (prev != curr->left)
            return false;
    else if (curr->right && !curr->left)
        if (prev != curr->right)
            return false;
    else
        if (prev != curr->right)
            return false;
    return true;
}

TreeNode* findLCA(TreeNode* root, TreeNode *a, TreeNode *b)
{
    vector<TreeNode*> v;
    vector<TreeNode*> pathA;
    vector<TreeNode*> pathB;
    
    bool foundA = false;
    bool foundB = false;
    
    TreeNode *prev = null;
    
    if (!root)
        return null;
    
    v.push_back(root);
    while (!v.empty() && (!foundA && !foundB)) {
        // Get the current node being processed
        TreeNode * curr = v.back();
        
        if (curr == a) {
            foundA = true;
            for (int i = 0; i < v.size(); i++)
                pathA.push_back(v[i]);
        }
        
        if (curr == b) {
            foundB = true;
            for (int i = 0; i < v.size(); i++)
                pathB.push_back(v[i]);
        }
        
        if (!curr->left && !curr->right) {
            // Case 1 : Hit leaf
            prev = curr;
            v.pop_back();
            
        } else if (curr->left && prev != curr->left) {
            // Case 2 : Left child not visited
            v.push_back(curr->left);
        } else if (curr->right && prev != curr->right) {
            // Case 3 : Right child not visited
            v.push_back(curr->right);
        } else if (areChildrenVisited(curr, prev)) {
            // Case 4: Both children visited
            prev = curr;
        }
        
    }
    
    // Compare both the path vectors
    int minLen = min(pathA.size(), pathB.size());
    for (int i = 0; i < minLen; i++) {
        if (pathA[i] != pathB[i])
            return pathA[i-1];
    }
    return pathA[minLen - 1];
}

/* Method 2:
One can recursively do a 'PREORDER' traversal and
if either a or b is found, pass up root to the parent.
If both are non null then that node is the LCA.
--------------------------------------------------------
Time Complexity = O(n) where n is the number of nodes 
Space Complexity = O(h) where h is height of binary tree
--------------------------------------------------------
*/
TreeNode* findLCA(TreeNode* root, TreeNode *a, TreeNode* b)
{
    if (!root)
        return null;
    
    // Do pre-order traversal
    if (root == a || root == b)
        return root;
    
    TreeNode *l = findLCA(root->left, a, b);
    TreeNode *r = findLCA(root->right, a, b);
    
    if (l != null && r != null)
        return root;
    
    return l == null ? r : l;
}
