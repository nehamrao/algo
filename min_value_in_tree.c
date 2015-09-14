/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
/* Determine the minimum value in a binary
 * tree given the root node. In a binary tree
 * the leftmost child is the one with the min value
 */
int minValue (struct node *root) {
    int ret = 0;
    struct node * prev = NULL;
    if (!root)
        assert(0);
     
    while (root && root->left) {
        prev = root;
        root = root->left;
    }
    return prev->val;
}

