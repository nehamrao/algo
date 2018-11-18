// Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
/*
 * Function to calculate the max depth of 
 * a binary tree recursively.
 */
int maxDepth(struct TreeNode* root) {
    if (!root)
        return 0;
        
    int llen = maxDepth(root->left);
    int rlen = maxDepth(root->right);
    
    if (llen > rlen)
        return llen+1;
    else return rlen+1;    
}

