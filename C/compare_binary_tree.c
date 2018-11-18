#include <stdio.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

/*
 * Determine if two binary trees are equal.
 * Two binary trees are considered equal if they are 
 * structurally identical and the nodes have the same value. 
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
    bool l = false, r = false;
    
    //Check for NULL 
    if (!p && !q)
        return true;
    
    //Check fo value and recurse over left/right ptr    
    if (p && q && (p->val == q->val)){
       l = isSameTree(p->left,q->left);
       r = isSameTree(p->right,q->right);
    }

    //If both left and right comparisons succeed, return true
    if (l && r)
        return true;
        
    return false;    
}

