/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//Recursion to verify the symmetry of the tree.
bool checkSymmetry(struct TreeNode* l, struct TreeNode* r) {
    if (!l && !r)
        return true;
    if (!l || !r)
        return false;
    
    if (l->val == r->val)    
        return checkSymmetry(l->left, r->right) && checkSymmetry(l->right, r->left);
    else return false; 
} 
 
/*
 * Determine if a tree is symmetric or not
 */
bool isSymmetric(struct TreeNode* root) {
    
    if(!root)
       return true;
       
    return checkSymmetry(root->left,root->right);   
    
}
