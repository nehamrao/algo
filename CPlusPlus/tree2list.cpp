#include<iostream>

using namespace std;

struct TreeNode* node {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* prev = NULL;
TreeNode* head = NULL;
TreeNode* tail = NULL;

void inOrderTr(TreeNode* root, TreeNode* prev)
{
    // Do the in-order traversal
    if (!root) return;
    
    inOrderTr(root->left, prev);
    
    // Processing in between
    if (prev == NULL) {
        head = prev;
        // Update prev
	prev = root;
    } else {
        prev->right = root;
        root->left = prev
        // Updat prev
        prev = root;
	tail = root;
    }
    inOrderTr(root->right, prev);
}

int main ()
{
    // Assume we have the root of the tree
    inOrderTr(root, head);
    // Final attachment
    tail->right = head;
    head->left = tail;
}
