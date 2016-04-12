/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValidBST2(struct TreeNode* root, long min, long max) {
     if (!root) return true;
     
     // Violating min, max
     if(root->val <= min || root->val >= max) return false;
     
     if (root->right && root->left) {
         if (root->right->val > root->val && root->left->val < root->val) {
             return isValidBST2(root->right, (long) root->val, max) && isValidBST2(root->left, min, (long) root->val);
         }
         return false;
     } else if (root->right) {
         if (root->right->val > root->val) {
             return isValidBST2(root->right, (long) root->val, max);
         }
         return false;
     } else if (root->left) {
         if (root->left->val < root->val) {
             return isValidBST2(root->left, min, (long) root->val);
         }
         return false;
     }
     return true;
}
 
bool isValidBST(struct TreeNode* root) {
    long min = ((long) INT_MIN) - 1;
    long max = ((long) INT_MAX) + 1;
    return isValidBST2(root, min, max);
}
