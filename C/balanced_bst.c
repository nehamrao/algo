#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a,b) (a > b ? a : b)

// Function to determine the depth of a binary search tree
int depth (struct TreeNode* root) {
    if (!root)
        return 0;
    else return(1 + MAX(depth(root->left), depth(root->right)));    
} 
 
// Function to determine if a BST is balanced or not
bool isBalanced(struct TreeNode* root) {
    if (!root)
        return true;
    
    /*
     * A BST is balanced if: a) left half is balanced and b) right half
     * is balanced and c) the difference between in depths is no more than 1
     */
    if (isBalanced(root->left) && isBalanced(root->right) && (abs(depth(root->left) - depth(root->right)) <= 1))
        return true;
    
    return false;  
}
