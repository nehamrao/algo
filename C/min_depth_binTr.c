/*
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along 
 * the shortest path from the root node down to the 
 * nearest leaf node.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int min (int a, int b) {
    return (a > b) ? b : a;
}

int minDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    } 
    if (root->left && !root->right)
        return minDepth(root->left) + 1;
    else if (root->right && !root->left)
        return minDepth(root->right) +1;
    else 
        return min(minDepth(root->left), minDepth(root->right)) + 1;
}
