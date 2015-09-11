/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
 * Function to invert a binary tree
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *tmp = NULL;
    
    if (!root)
        return NULL;
    
    //Swap the left and right pointers 
    if (root) {
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

    //Recursively swap the left/right pointers of child nodes
    root->right = invertTree(root->right);
    root->left = invertTree(root->left);
    
    return root;
}
