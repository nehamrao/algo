/*
 * This file contains tree traversals
 * for a binary tree
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

/* PreOrder (Iterative, with stack) */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> result;
        
        if (!root)
            return result;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            if (curr && curr->right) {
                s.push(curr->right);
            }
            if (curr && curr->left) {
                s.push(curr->left);
            }
            result.push_back(curr->val);
        }
        return result;
    }
};

/* PreOrder (Iterative, no stack) */

class Solution {
public:

bool areChildrenVisited(TreeNode* prev, TreeNode* node) {
        // Only left node
        if (node->left && !node->right) {
            if (prev != node->left) return false;
        }
        // Only right node
        else if (!node->left && node->right) {
            if (prev != node->right) return false;
        }
        // Both nodes
        else {
            if (prev != node->right) return false;
        }
        return true;
}
    
    vector<int> preorderTraversal(TreeNode* root) {
         vector<TreeNode*> v;
        vector<int> ret;
        TreeNode* prev = NULL;
       
        if (!root) return ret;
        v.push_back(root);
        while (!v.empty()) {
            TreeNode* curr = v.back();
    
            // Leaf node
            if (!curr->left && !curr->right) {
                ret.push_back(curr->val);
                prev = curr;
                v.pop_back();
            }
    
            // Both children visited
            else if (areChildrenVisited(prev, curr)) {
                prev = curr;
                v.pop_back();
            }
    
           // Left child not visited
           else if (curr->left && (prev != curr->left)) {
               ret.push_back(curr->val);
               v.push_back(curr->left);
           }
           
           // Right child not visited
           else if (curr->right && (prev != curr->right)) {
               if (!curr->left) ret.push_back(curr->val);
               v.push_back(curr->right);
           }
            
        }
        return ret;
    }
};


/* PreOrder (Iterative, Morris) */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        TreeNode* curr = root;
        while (curr) {
            // No left subtree
            if (!curr->left) {
                v.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find right most predecessor of left sub-tree
                TreeNode* predecessor = curr->left;
                while (predecessor->right != NULL && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }
                // If we hit NULL, not threaded
                if (predecessor->right == NULL) {
                    predecessor->right = curr;
                    v.push_back(curr->val);
                    curr = curr->left;
                } else if (predecessor->right == curr) {
                    // If threaded
                    predecessor->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return v;
    }
};


/* PreOrder Recursive) */

class Solution {
public:
    void preorderHelper (TreeNode* node, vector<int>& v) {
        if (!node)
            return;
            
        v.push_back(node->val);
        preorderHelper(node->left, v);
        preorderHelper(node->right, v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorderHelper(root, v);
        return v;
    }
};

/* PostOrder (Iterative, with stack) */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        bool first = false;
        if (!root)
            return v;
            
        /*
         * This is an elegant solution wherein we first determine the
         * first element in the post-order traversal and then on
         * the stack would store the right child, parent from bottom up.
         * But we want it to store parent, right child so we will pop and
         * re-add the same elment to the stack (i.e if the node has a right child)
         */
         TreeNode* curr = root;
         while (!s.empty() || curr != NULL ) {
             // Initial population of the stack 
             while (curr != NULL) {
                 if (curr->right) s.push(curr->right);
                 s.push(curr);
                 curr = curr->left;
             }
             
             curr = s.top();
             s.pop();
             // Special case of modifying the stack
             if (curr->right != NULL && !s.empty() && curr->right == s.top()) {
                 s.pop();
                 s.push(curr); // Push the parent
                 curr = curr->right; // Now go to the right
             } else {
                 v.push_back(curr->val);
                 curr= NULL;
             }
         }
         return v;
    }
};

/* PostOrder (Iterative, no stack) */

class Solution {
public:

    bool areChildrenVisited(TreeNode* prev, TreeNode* node) {
        // Only left node
        if (node->left && !node->right) {
            if (prev != node->left) return false;
        }
        // Only right node
        else if (!node->left && node->right) {
            if (prev != node->right) return false;
        }
        // Both nodes
        else {
            if (prev != node->right) return false;
        }
        return true;
}
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> v;
        vector<int> ret;
        TreeNode* prev = NULL;
       
        if (!root) return ret;
        v.push_back(root);
        while (!v.empty()) {
            TreeNode* curr = v.back();
    
            // Leaf node
            if (!curr->left && !curr->right) {
                ret.push_back(curr->val);
                prev = curr;
                v.pop_back();
            }
    
            // Both children visited
            else if (areChildrenVisited(prev, curr)) {
                ret.push_back(curr->val);
                prev = curr;
                v.pop_back();
            }
    
           // Left child not visited
           else if (curr->left && (prev != curr->left)) {
               v.push_back(curr->left);
           }
           
           // Right child not visited
           else if (curr->right && (prev != curr->right)) {
               v.push_back(curr->right);
           }
            
        }
        return ret;
    }
};

/* PostOrder Recursive) */

class Solution {
public:
    void postorderTravHelper (TreeNode* root, vector<int>& v) {
        
        if (!root)
            return;
        postorderTravHelper(root->left, v);
        postorderTravHelper(root->right, v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
            
        postorderTravHelper(root, v);
        return v;
    }
};

/* InOrder (Iterative, with stack) */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            v.push_back(curr->val);
            curr = curr->right;
        }
        return v;
    }
};

/* InOrder (Iterative, no stack) */

class Solution {
public:
    
// New
 bool areChildrenVisited(TreeNode* prev, TreeNode* node) {
        // Only left node
        if (node->left && !node->right) {
            if (prev != node->left) return false;
        }
        // Only right node
        else if (!node->left && node->right) {
            if (prev != node->right) return false;
        }
        // Both nodes
        else {
            if (prev != node->right) return false;
        }
        return true;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> v;
        vector<int> ret;
        TreeNode* prev = NULL;
       
        if (!root) return ret;
        v.push_back(root);
        while (!v.empty()) {
            TreeNode* curr = v.back();
    
            // Leaf node
            if (!curr->left && !curr->right) {
                prev = curr;
                ret.push_back(curr->val);
                v.pop_back();
            }
    
            // Both children visited
            else if (areChildrenVisited(prev, curr)) {
                // Only in case of empty right path for tree
                if (!curr->right)
                    ret.push_back(curr->val);
                prev = curr;
                v.pop_back();
            }
    
           // Left child not visited
           else if (curr->left && (prev != curr->left)) {
               v.push_back(curr->left);
           }
           
           // Right child not visited
           else if (curr->right && (prev != curr->right)) {
               ret.push_back(curr->val);
               v.push_back(curr->right);
           }
            
        }
        return ret;
   }

};

/* InOrder (Iterative, Morris) */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        TreeNode* curr = root;
        
        while (curr) {
            if (!curr->left) {
                v.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* predecessor = curr->left;  
                while (predecessor->right != NULL && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }
                // Threaded
                if (predecessor->right == curr) {
                    predecessor->right = NULL;
                    v.push_back(curr->val);
                    curr = curr->right;
                } else if (predecessor->right == NULL){
                    predecessor->right = curr;
                    curr = curr->left;
                }
            }      
        }
        return v;
    }
};

/* InOrder Recursive) */

class Solution {
public:

    void inorderTravHelper(TreeNode* root, vector<int>& v) {
        if (!root)
            return;
        inorderTravHelper(root->left, v);
        v.push_back(root->val);
        inorderTravHelper(root->right, v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorderTravHelper(root, v);
        return v;
    }
};

